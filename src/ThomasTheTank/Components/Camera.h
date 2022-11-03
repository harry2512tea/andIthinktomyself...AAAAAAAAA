#ifndef THOMASTHETANK_CAMERA_H
#define THOMASTHETANK_CAMERA_H

//#include <rend/rend.h>
#include "ThomasTheTank/Wrapping/ThomasMath.h"
#include "../Component.h"
#include <memory>
#include <list>


namespace ThomasTheTank
{
	/**
	* Component ability to render from camera object
	*/
	struct Camera : Component, std::enable_shared_from_this<Camera>
	{
		/**
		* Generate the projection matrix of the camera
		* 
		* \return generated projection matrix
		*/
		mat4 getProjection();
		/**
		* Generate the view matrix of the camera
		* 
		* \return generated view matrix
		*/
		mat4 getView();

		/**
		* Get a pointer to the main camera in the scene
		*
		* \return pointer to the current main camera
		*/
		static Shared<Camera> main();

		/**
		* Set the main camera of the scene
		*
		* \param shared pointer to the new main camera
		*/
		void setMainCam(Shared<Camera> newMain) { mainCam = newMain; };
	private:
		void onInitialize(); ///< function called on the creation of the component
		void onDestroy(); ///< funciton called on the destruction of the component
		static Shared<Camera> mainCam; ///< pointer to the current main camera of the scene
		static std::list<Weak<Camera>> cameras; ///< list of all cameras in the scene
		void AddCam(Weak<Camera> cam) { Camera::cameras.push_back(cam); }; ///< Adds camera to the list of scene cameras
		float FOV = 70; ///< Field of view of the camera
		float nearClip = 0.1f; ///< Near clipping plane of the camera
		float farClip = 1000; ///< Far clipping plane of the camera
	};
}

#endif