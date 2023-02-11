#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <string>

#include "../Component.h"

namespace ThomasTheTank
{
	struct AudioClip;

	struct AudioSource : Component
	{
		/*
		* Main constructor of the audio source component.
		* 
		* \param _path STRING path to the audio file used by the component
		*/

		void Play(); ///< Start playing the audio clip
		void Stop(); ///< Stop playing the audio clip
		void setClip(Shared<AudioClip> _clip) { m_clip = _clip; };
		void setVolume(float volume) { m_volume = volume; };
		float getVolume() { return m_volume; };

		void setPitch(float pitch) { m_pitch = pitch; };
		float getPitch() { return m_pitch; };
		void setLoop(bool _loop) { loop = _loop; };

	private:

		//void onDestroy(); ///< Function called on destruction of the component.
		void onTick(); ///< Function called every frame.
		//void onInitialize(); ///< Function called on creation of the component.

		Shared<AudioClip> m_clip;

		bool playing = false;
		bool loop = false; ///< whether or not the audio clip should be looped.
		ALfloat m_volume = 1.0f; ///< volume when playing the audio clip
		ALfloat m_pitch = 2.0f;
	};
}