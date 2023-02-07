#ifndef THOMASTHETANK_RIGIDBODY_H
#define THOMASTHETANK_RIGIDBODY_H

#include <memory>
#include <PhysB/PhysB.h>
#include "../Component.h"

namespace ThomasTheTank
{
	struct RigidBody : Component
	{
		/**
		* Function to add a force to the rigidbody
		* 
		* \param force VEC3 force vector
		* 
		* \param _mode FORCEMODE type of force to apply
		*/
		void AddForce(glm::vec3 force, PhysB::ForceMode _mode = PhysB::Impulse);

		/**
		* Function to get the mass of the rigidbody
		* 
		* \return FLOAT
		*/
		float getMass();

		/**
		* Function to set the mass of the rigidbody
		* 
		* \param _mass FLOAT
		*/
		void setMass(float _mass);

		/**
		* Function to get whether the rigidbody uses gravity
		* 
		* \return BOOL
		*/
		bool getUseGravity();

		/**
		* Function to set whether the rigidbody uses gravity
		* 
		* \param _Gravity BOOL
		*/
		void setUseGravity(bool _gravity);

		/**
		* Function to get the velocity of the rigidbody
		* 
		* \return VEC3
		*/
		vec3 getVelocity();

		/**
		* Function to set the velocity of the rigidbody
		* 
		* \param _velocity VEC3
		*/
		void setVelocity(vec3 _vel);

		/**
		* Function to get the angular velocity of the rigidbody
		*
		* \return VEC3
		*/
		vec3 getAngularVelocity();

		/**
		* Function to set the angular velocity of the rigidbody
		*
		* \param _velocity VEC3
		*/
		void setAngularVelocity(vec3 _vel);

		/**
		* Function to get the elasticity of the rigidbody
		* 
		* \return FLOAT
		*/
		float getElasticity();

		/**
		* Function to set the elasticity of the rigidbody
		* 
		* \param _elasticity FLOAT
		*/
		void setElasticity(float _elasticity);

		/**
		* Function to get the friction of the rigidbody
		* 
		* \return FLOAT
		*/
		float getFriction();

		/**
		* Function to set the friction of the rigidbody
		* 
		* \param _friction FLOAT
		*/
		void setFriction(float _friction);

	private:
		friend struct BoxCollider;
		void onInitialize(); ///< Function called on creation of the struct
		void onDestroy(); ///< Function called on destruction of the struct
		Shared<PhysB::PhysRigidBody> m_body; ///< link to the corresponding rigidbody in the physics world.
	};
}
#endif // !THOMASTHETANK_RIGIDBODY_H