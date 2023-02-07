#ifndef THOMASTHETANK_AUDIOCLIP_H
#define THOMASTHETANK_AUDIOCLIP_H

#include "ThomasTheTank/Components/Resource.h"
#include <rend/rend.h>
#include <list>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
#include <stdexcept>

namespace ThomasTheTank
{
	struct AudioSource;

	struct AudioClip : Resource
	{
		/**
		* Load the Audio clip from a file
		* 
		* \param _path STRING path to the file to load from.
		*/
		void LoadClip(const std::string _path);

		void OnLoad();

	private:
		friend struct AudioSource;
		ALenum m_format; ///< Format of the audio clip
		ALsizei m_freq; ///< Frequency of the audio clip
		ALint m_volume = 1.0f; ///< volume when playing the audio clip
		ALuint m_bufferId; 
		ALuint m_sourceId;
	};
}

#endif 