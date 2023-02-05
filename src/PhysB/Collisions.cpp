#include "Collisions.h"
#include "Collider.h"
#include "CollisionDet.h"
#include "PhysTransform.h"
#include "PhysAABB.h"


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
		vec3 intersect, normal;
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
