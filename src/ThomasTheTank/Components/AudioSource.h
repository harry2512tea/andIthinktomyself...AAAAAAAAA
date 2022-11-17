#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <string>

#include "../Component.h"

namespace ThomasTheTank
{

	struct AudioSource : Component
	{
		AudioSource(std::string _path);
		AudioSource();

		void Play();

	private:

		void onDestroy();
		void onTick();
		void onInitialize();

		bool loop = true;
		ALenum m_format;
		ALsizei m_freq;
		ALuint m_bufferId;
		ALuint m_sourceId;
	};
}