#include <iostream>
#include "../Components/Transform.h"
#include "../Core.h"

namespace ThomasTheTank
{
	void Transform::onTick()
	{
		rotation = checkRoationValues(rotation);
	}


	quat Transform::generateRotQuat(vec3 _rotation)
	{
		quat x = glm::angleAxis(radians(_rotation.x), vec3(1.0f, 0.0f, 0.0f));
		quat y = glm::angleAxis(radians(_rotation.y), vec3(0.0f, 1.0f, 0.0f));
		quat z = glm::angleAxis(radians(_rotation.z), vec3(0.0f, 0.0f, 1.0f));
	
		return x * y * z;
	}


	void Transform::rotate(vec3 _rotation)
	{
		localRotation += _rotation;
		rotationQuat = generateRotQuat(localRotation);
	}

	Shared<PhysB::PhysTransform> Transform::addPhysicsTransform()
	{
		Shared<PhysB::PhysTransform> temp;
		if (!m_PhysTransform)
		{
			m_PhysTransform = getCore()->getPhysics()->AddTransform();
			temp = m_PhysTransform;
		}
		else
		{
			temp = m_PhysTransform;
		}

		return temp;

	}

	mat4 Transform::generateModel(vec3 _position, vec3 _rotation, vec3 _scale)
	{
		rotationMat = mat4(1.0f);
		translationMat = mat4(1.0f);
		scaleMat = mat4(1.0f);
		mat4 _model = mat4(1.0f);

		quat _rotationQuat = generateRotQuat(_rotation);

		translationMat = glm::translate(translationMat, _position);
		rotationMat = mat4_cast(_rotationQuat);
		scaleMat = glm::scale(scaleMat, _scale);
		
		_model = (translationMat * rotationMat * scaleMat);

		return _model;
	}

	mat4 Transform::getParentMatrix()
	{
		Shared<Transform> _parent = Parent.lock();

		mat4 parentMatrix = mat4(1.0f);

		if (_parent)
		{
			while (_parent)
			{
				parentMatrix = _parent->getParentMatrix() * parentMatrix;
				_parent = _parent->getParent();
			}
		}

		return parentMatrix;
	}

	vec3 Transform::checkRoationValues(vec3 _rot)
	{
		if (_rot.x > 360)
		{
			_rot.x -= 360;
		}
		else if (_rot.x < -360)
		{
			_rot.x += 360;
		}
		if (_rot.y > 360)
		{
			_rot.y -= 360;
		}
		else if (_rot.y < -360)
		{
			_rot.y += 360;
		}
		if (_rot.z > 360)
		{
			_rot.z -= 360;
		}
		else if (_rot.z < -360)
		{
			_rot.z += 360;
		}

		return _rot;
	}

	void Transform::onInitialize()
	{
		model = generateModel(localPosition, localRotation, localScale);
	}


	void Transform::setRotation(vec3 _rotation)
	{
		if (Parent.lock())
		{
			localRotation - Parent.lock()->getRotation();
		}
		else
		{
			localRotation = _rotation;
		}

		rotationQuat = generateRotQuat(localRotation);
	}

	void Transform::setPosition(vec3 _pos)
	{
		if (Parent.lock())
		{
			mat4 transMat = mat4(1.0f);
			Shared<Transform> _parent = Parent.lock();

			while (_parent)
			{
				transMat = transMat * _parent->generateModel(_parent->localPosition, _parent->localRotation, vec3(1.0f));
				_parent = _parent->Parent.lock();
			}

			localPosition = inverse(transMat) * vec4(_pos, 1.0f);
		}
		else
		{
			localPosition = _pos;
		}
	}


	void Transform::setScale(vec3 _scale)
	{
		if (Parent.lock())
		{
			mat4 transMat = mat4(1.0f);
			Shared<Transform> _parent = Parent.lock();

			while (_parent)
			{
				transMat = transMat * generateModel(_parent->localPosition, _parent->localRotation, vec3(1.0f));
			}

			localScale = inverse(transMat) * vec4(_scale, 1.0f);
		}
	}

	vec3 Transform::getPosition()
	{
		mat4 transMat = mat4(1.0f);
		Shared<Transform> _parent = std::dynamic_pointer_cast<Transform>(m_self.lock());

		while (_parent)
		{
			transMat = transMat * generateModel(_parent->localPosition, _parent->localRotation, vec3(1.0f));
			_parent = _parent->Parent.lock();
		}

		return transMat * vec4(vec3(0.0f), 1.0f);
	}

	vec3 Transform::getRotation()
	{
		vec3 rot = vec3(0.0f);
		Shared<Transform> _parent = std::dynamic_pointer_cast<Transform>(m_self.lock());

		while (_parent)
		{
			rot += _parent->localRotation;
			_parent = _parent->Parent.lock();
		}

		rot = checkRoationValues(rot);

		return rot;
	}

	vec3 Transform::getScale()
	{
		return localScale;
	}

}