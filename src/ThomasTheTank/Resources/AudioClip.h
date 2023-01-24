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
		void LoadClip(const std::string _path);

		void OnLoad();

	private:
		friend struct AudioSource;
		ALenum m_format;
		ALsizei m_freq;
		ALint m_volume = 1.0f;
		ALuint m_bufferId;
		ALuint m_sourceId;
	};
}

#endif 