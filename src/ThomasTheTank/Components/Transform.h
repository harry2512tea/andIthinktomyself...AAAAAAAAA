#ifndef THOMASTHETANK_TRANSFORM_H
#define THOMASTHETANK_TRANSFORM_H

#include "../Wrapping/ThomasMath.h"
#include "../Component.h"
#include <list>

namespace ThomasTheTank
{
	/**
	* Component containing information about the state of the entity.
	*/
	struct Transform : Component
	{
	public:
		/**
		* Set the position.
		* 
		* \param VEC3 pos The new position.
		*/
		void setPosition(vec3 pos);

		/**
		* Set the rotation.
		*
		* \param VEC3 rot The new rotation.
		*/
		void setRotation(vec3 rot);

		/**
		* Set the scale.
		*
		* \param VEC3 _scale The new scale.
		*/
		void setScale(vec3 _scale);

		/**
		* Rotate the object.
		* 
		* \param VEC3 rot How far to rotate the object.
		*/
		void rotate(vec3 rot);

		/**
		* Translate the object.
		*
		* \param VEC3 translation How far to translate the object.
		*/
		void translate(vec3 translation) { localPosition += translation; };

		/**
		* Get the position.
		* 
		* \return VEC3 The position of the object.
		*/
		vec3 getPosition();

		/**
		* Get the rotation.
		*
		* \return VEC3 The rotation of the object.
		*/
		vec3 getRotation();

		/**
		* Get the quaternion for the object's rotation.
		*
		* \return QUAT The rotation quaternion of the object.
		*/
		quat getRotationQuat() { return rotationQuat; };

		/**
		* Get the scale.
		*
		* \return VEC3 The scale of the object.
		*/
		vec3 getScale();

		/**
		* Get the transformation matrix of the entity.
		* 
		* \return MAT4 The model's transformation matrix.
		*/
		mat4 getModel() { return generateModel(localPosition, localRotation, localScale); };

		Shared<Transform> getParent() { return Parent.lock(); };

	private:
		friend struct Transform;
		Weak<Transform> Parent;
		std::list<Weak<Transform>> Children;

		mat4 generateModel(vec3 _position, vec3 _rotation, vec3 _scale);
		quat generateRotQuat(vec3 _rotation); ///< Convert Euler angles to a quaternion.
		void onTick(); ///< Function called on every program tick.
		void onInitialize();

		vec3 position = vec3(0.0f); ///< Global X, Y, Z location of the Entity.
		vec3 rotation = vec3(0.0f); ///< Global Rotation of the entity in euler angles.
		vec3 scale = vec3(1.0f); ///< Global Scale of the entity.
		quat rotationQuat = quat(); ///< Global Orientation of the entity in a Quaternion.

		vec3 localPosition = vec3(0.0f); ///< Local X, Y, Z location of the Entity.
		vec3 localRotation = vec3(0.0f); ///< Local Rotation of the entity in euler angles.
		vec3 localScale = vec3(1.0f); ///< Local Scale of the entity.

		mat4 rotationMat = mat4(1.0f);
		mat4 translationMat = mat4(1.0f);
		mat4 scaleMat = mat4(1.0f);
		mat4 model = mat4(1.0f);

		mat4 getParentMatrix();

		vec3 checkRoationValues(vec3 _rot); ///< Confine Euler angle rotation between 360 and -360 degrees.
	};
}

#endif