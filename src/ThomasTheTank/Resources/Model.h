#ifndef THOMASTHETANK_MODEL_H
#define THOMASTHETANK_MODEL_H

#include "ThomasTheTank/Components/Resource.h"
#include <rend/rend.h>
#include <list>

namespace ThomasTheTank
{
	struct MeshRenderer;

	struct Model : Resource
	{

		/**
		* Function to load a model from a specified file
		* 
		* \param _path STRING path to model file
		*/
		void LoadModel(const std::string _path);

		void OnLoad();

	private:
		friend struct MeshRenderer;
		Shared<rend::Model> m_model; ///< link to the loaded model.
	};
}
#endif // !THOMASTHETANK_MODEL_H