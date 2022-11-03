#ifndef THOMASTHETANK_TRANSFORM_H
#define THOMASTHETANK_TRANSFORM_H

#include "../Wrapping/ThomasMath.h"
#include "../Component.h"

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
		* \param pos The new position.
		*/
		void setPosition(vec3 pos) { position = pos; };

		/**
		* Set the rotation.
		*
		* \param rot The new rotation.
		*/
		void setRotation(vec3 rot);

		/**
		* Set the scale.
		*
		* \param _scale The new scale.
		*/
		void setScale(vec3 _scale) { scale = _scale; };

		/**
		* Rotate the object.
		* 
		* \param rot How far to rotate the object.
		*/
		void rotate(vec3 rot);

		/**
		* Translate the object.
		*
		* \param translation How far to translate the object.
		*/
		void translate(vec3 translation) { position += translation; };

		/**
		* Get the position.
		* 
		* \return The position of the object.
		*/
		vec3 getPosition() { return position; };

		/**
		* Get the rotation.
		*
		* \return The rotation of the object.
		*/
		vec3 getRotation() { return rotation; };

		/**
		* Get the quaternion for the object's rotation.
		*
		* \return The rotation quaternion of the object.
		*/
		quat getRotationQuat() { return rotationQuat; };

		/**
		* Get the scale.
		*
		* \return The scale of the object.
		*/
		vec3 getScale() { return scale; };

		/**
		* Generate the model matrix based on the position, rotation and scale.
		* 
		* \return The generated model matrix.
		*/
		mat4 getModel();

	private:
		quat generateRotQuat(vec3 _rotation); ///< Convert Euler angles to a quaternion.
		void onTick(); ///< Function called on every program tick.

		vec3 position = vec3(0.0f); ///< X, Y, Z location of the Entity.
		vec3 rotation = vec3(0.0f); ///< Rotation of the entity in euler angles.
		vec3 scale = vec3(1.0f); ///< Scale of the entity.
		quat rotationQuat = quat(); ///< Rotation of the entity in a Quaternion.

		vec3 checkRoationValues(vec3 _rot); ///< Confine Euler angle rotation between 360 and -360 degrees.
	};
}

#endif