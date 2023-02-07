#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <string>

#include "../Component.h"

namespace ThomasTheTank
{

	struct AudioSource : Component
	{
		/*
		* Main constructor of the audio source component.
		* 
		* \param _path STRING path to the audio file used by the component
		*/
		AudioSource(std::string _path);
		AudioSource();

		void Play(); ///< Start playing the audio clip

	private:

		void onDestroy(); ///< Function called on destruction of the component.
		void onTick(); ///< Function called every frame.
		void onInitialize(); ///< Function called on creation of the component.

		bool loop = true; ///< whether or not the audio clip should be looped.
		ALenum m_format; ///< format of the audio clip.
		ALsizei m_freq; ///< frequency of the audio clip.
		ALint m_volume = 1.0f; ///< volume when playing the audio clip
		ALuint m_bufferId;
		ALuint m_sourceId;
	};
}