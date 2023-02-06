#include "Collisions.h"
#include "Collider.h"
#include "CollisionDet.h"
#include "PhysTransform.h"
#include "PhysAABB.h"
#include "PhysRigidBody.h"


namespace PhysB
{
	
	Shared<CollisionInfo> Collisions::CheckCollision(Shared<PhysCollider> Col1, Shared<PhysCollider> Col2)
	{
		Shared<CollisionInfo> temp = mkShared<CollisionInfo>();
		temp->colliding = false;
		temp->Col1 = Col1;
		temp->Col2 = Col2;

		switch (Col1->getType())
		{
		case Box:
			switch (Col2->getType())
			{
			case Box:
				BoxBox(temp);
				break;
			case Sphere:
				break;
			}
			break;
		case Sphere:
			switch (Col2->getType())
			{
			case Box:
				break;
			case Sphere:
				break;
			}
			break;
		}
		
		return temp;

	}

	void Collisions::BoxBox(Shared<CollisionInfo> colInfo)
	{
		mat4 Col1Mat = colInfo->Col1->m_trans->getModelMat();
		mat4 Col2Mat = colInfo->Col2->m_trans->getModelMat();
		Shared <PhysAABB> Col1 = std::dynamic_pointer_cast<PhysAABB>(colInfo->Col1);
		Shared <PhysAABB> Col2 = std::dynamic_pointer_cast<PhysAABB>(colInfo->Col2);
		std::vector<vec3> normalsToTest;
		std::vector<vec3> Col1Points;
		std::vector<vec3> Col2Points;
		for (int I = 0; I < Col1->Planes.size(); I++)
		{
			normalsToTest.push_back(Col1->Planes.at(I)->getNormal());
		}
		for (int I = 0; I < Col2->Planes.size(); I++)
		{
			normalsToTest.push_back(Col2->Planes.at(I)->getNormal());
		}
		for (int I = 0; I < Col1->points.size(); I++)
		{
			Col1Points.push_back(Col1->points.at(I));
		}
		for (int I = 0; I < Col2->points.size(); I++)
		{
			Col2Points.push_back(Col2->points.at(I));
		}

		std::vector<Axis> axis;
		for (int I = 0; I < Col1->Planes.size(); I++)
		{
			axis.push_back(projOntoAxis(Col1Points, normalsToTest[I]));
		}
		for (int I = Col1->Planes.size(); I < normalsToTest.size(); I++)
		{
			axis.push_back(projOntoAxis(Col2Points, normalsToTest[I]));
		}
	
		int halfSize = axis.size() / 2;
		colInfo->colliding = true;

		for (size_t I = 0; I < axis.size() / 2; I++)
		{
			if (axis[I].maxProj < axis[I + halfSize].minProj || axis[I + halfSize].maxProj < axis[I].minProj)
			{
				colInfo->colliding = false;
				break;
			}
		}

		if (colInfo->colliding)
		{
			BoxBoxColPoint(colInfo);
		}

	}

	void Collisions::BoxBoxColPoint(Shared<CollisionInfo> colInfo)
	{
		Shared <PhysAABB> Col1 = std::dynamic_pointer_cast<PhysAABB>(colInfo->Col1);
		Shared <PhysAABB> Col2 = std::dynamic_pointer_cast<PhysAABB>(colInfo->Col2);
		vec3 col1Point = Col1->Transform()->getPosition();
		vec3 col2Point = Col2->Transform()->getPosition();
		vec3 intersect, normal, collidingPoint;
		Shared<Plane> collisionPlane;
		Shared<PhysCollider> ColliderToMove, ColliderPlane;
		float dist = 0;
		vec3 temp;
		for (size_t Point = 0; Point < Col1->points.size(); Point++)
		{
			Shared<Ray> ray = std::make_shared<Ray>(Col1->points.at(Point) - col1Point, col1Point);
			for (size_t Plane = 0; Plane < Col2->Planes.size(); Plane++)
			{
				Col2->Planes.at(Plane)->getIntersect(ray, temp);
				if (distance(col1Point, temp) < dist || Plane == 0)
				{
					normal = Col2->Planes.at(Plane)->getNormal();
					ColliderPlane = Col2;
					ColliderToMove = Col1;
					collisionPlane = Col2->Planes.at(Plane);
					collidingPoint = Col1->points.at(Point);
					intersect = temp;
					dist = distance(col1Point, temp);
				}
			}
		}

		for (size_t Point = 0; Point < Col2->points.size(); Point++)
		{
			Shared<Ray> ray = std::make_shared<Ray>(Col2->points.at(Point) - col2Point, col2Point);
			for (size_t Plane = 0; Plane < Col1->Planes.size(); Plane++)
			{
				Col1->Planes.at(Plane)->getIntersect(ray, temp);
				if (distance(col2Point, temp) < dist || Plane == 0)
				{
					normal = Col1->Planes.at(Plane)->getNormal();
					ColliderPlane = Col1;
					ColliderToMove = Col2;
					collisionPlane = Col1->Planes.at(Plane);
					collidingPoint = Col2->points.at(Point);
					intersect = temp;
					dist = distance(col2Point, temp);
				}
			}
		}
		colInfo->point = intersect;
		colInfo->normal = normal;
		colInfo->ColliderPlane = ColliderPlane;
		colInfo->ColliderToMove = ColliderToMove;
		colInfo->CollisionPlane = collisionPlane;
		colInfo->collidingPoint = collidingPoint;
	}

	void Collisions::CheckResponse(Shared<CollisionInfo> colInfo)
	{
		switch (colInfo->Col1->getType())
		{
		case Box:
			switch (colInfo->Col2->getType())
			{
			case Box:
				BoxBoxResponse(colInfo);
				break;
			case Sphere:
				break;
			}
			break;
		case Sphere:
			switch (colInfo->Col2->getType())
			{
			case Box:
				break;
			case Sphere:
				break;
			}
			break;
		}
	}

	void Collisions::BoxBoxResponse(Shared<CollisionInfo> colInfo)
	{
		Shared <PhysAABB> ColliderPlane = std::dynamic_pointer_cast<PhysAABB>(colInfo->ColliderPlane);
		Shared <PhysAABB> ColliderToMove = std::dynamic_pointer_cast<PhysAABB>(colInfo->ColliderToMove);
		Shared<Ray> ray;
		vec3 intersect;
		Shared<PhysRigidBody> Col1;
		Shared<PhysRigidBody> Col2;
		vec3 vel = vec3();
		vec3 totalMomentum = vec3();
		vec3 totalVelocity = vec3();
		vec3 Col1vel = vec3();
		vec3 Col2vel = vec3();
		vec3 velocityPerMass;
		vec3 velInDirection;
		float dist;
		float magInDirection;


		switch (ColliderPlane->isDynamic)
		{
		case true:
			switch (ColliderToMove->isDynamic)
			{
			case true:
				vel = ColliderToMove->m_RigidBody.lock()->getVelocity();

				ray = std::make_shared<Ray>(-vel, colInfo->collidingPoint);
				colInfo->CollisionPlane.lock()->getIntersect(ray, intersect);
				dist = distance(intersect, colInfo->collidingPoint);
				ColliderToMove->m_trans->Translate(-vel * dist);

				Col1 = ColliderToMove->m_RigidBody.lock();
				Col2 = ColliderPlane->m_RigidBody.lock();

				totalMomentum = (Col1->getVelocity() * Col1->getMass()) + (Col2->getVelocity() * Col2->getMass());
				totalVelocity = totalMomentum / (Col1->getMass() + Col2->getMass());
				velocityPerMass = totalVelocity / (Col1->getMass() + Col2->getMass());
				Col1vel = velocityPerMass * Col1->getMass();
				Col2vel = velocityPerMass * Col2->getMass();

				Col1->AddForce(Col1vel, VelocityChange);
				Col2->AddForce(Col2vel, VelocityChange);

				break;

			case false:
				vel = ColliderPlane->m_RigidBody.lock()->getVelocity();
				ray = std::make_shared<Ray>(vel, colInfo->collidingPoint);
				colInfo->CollisionPlane.lock()->getIntersect(ray, intersect);
				dist = distance(intersect, colInfo->collidingPoint);
				ColliderPlane->m_trans->Translate(-vel * dist);

				magInDirection = dot(vel, colInfo->CollisionPlane.lock()->getNormal());
				velInDirection = colInfo->CollisionPlane.lock()->getNormal() * magInDirection;
				ColliderPlane->m_RigidBody.lock()->AddForce(-velInDirection + (-velInDirection * ColliderPlane->m_RigidBody.lock()->getElasticity()));
				break;
			}
			break;
		case false:
			switch (ColliderToMove->isDynamic)
			{
			case true:
				vel = ColliderToMove->m_RigidBody.lock()->getVelocity();

				ray = std::make_shared<Ray>(-vel, colInfo->collidingPoint);
				colInfo->CollisionPlane.lock()->getIntersect(ray, intersect);
				dist = distance(intersect, colInfo->collidingPoint);
				ColliderToMove->m_trans->Translate(-vel * dist);

				magInDirection = dot(vel, -colInfo->CollisionPlane.lock()->getNormal());
				velInDirection = -colInfo->CollisionPlane.lock()->getNormal() * magInDirection;

				ColliderToMove->m_RigidBody.lock()->AddForce(-velInDirection + (-velInDirection * ColliderToMove->m_RigidBody.lock()->getElasticity()));
				break;
			case false:
				break;
			}
			break;
		}

		
	}

	Axis Collisions::projOntoAxis(std::vector<vec3> points, vec3 normal)
	{
		float minProjection = dot(points[0], normal);
		float maxProjection = minProjection;

		for (size_t I = 0; I < points.size(); I++)
		{
			float currentProj = dot(points.at(I), normal);

			if (minProjection > currentProj)
			{
				minProjection = currentProj;
			}
			if (currentProj > maxProjection)
			{
				maxProjection = currentProj;
			}
		}

		Axis rtn;
		rtn.maxProj = maxProjection;
		rtn.minProj = minProjection;
		rtn.normal = normal;
		return rtn;
	}

}