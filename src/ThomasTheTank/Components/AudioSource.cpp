#include "AudioSource.h"
#include <stdexcept>
#include "../Entity.h"
#include "Transform.h"
#include "../Resources/AudioClip.h"
#include "Camera.h"
#include <iostream>

namespace ThomasTheTank
{

	void AudioSource::Play()
	{
		if (m_clip)
		{
			alSourcePlay(m_clip->m_sourceId);
			playing = true;
		}
	}

	void AudioSource::Stop()
	{
		if (m_clip)
		{
			alSourceStop(m_clip->m_sourceId);
			playing = false;
		}
	}

	void AudioSource::onTick()
	{
		if (m_clip)
		{
			vec3 temp = getEntity()->getTransform()->getPosition();
			vec3 tempListener = Camera::main()->getEntity()->getTransform()->getPosition();

			float vol = 1 / distance(temp, tempListener) * m_volume;
			if (vol < 0.001f)
			{
				alSourcef(m_clip->m_sourceId, AL_GAIN, 0.0f);
			}
			else
			{
				alSourcef(m_clip->m_sourceId, AL_GAIN, m_volume);
			}
			//std::cout << temp.x << " " << temp.y << " " << temp.z << std::endl;
			alSource3f(m_clip->m_sourceId, AL_POSITION, temp.x, temp.y, temp.z);
			alSourcef(m_clip->m_sourceId, AL_PITCH, m_pitch);
			//alSourcef(m_sourceId, AL_GAIN, vol);

			int state = 0;
			alGetSourcei(m_clip->m_sourceId, AL_SOURCE_STATE, &state);

			if (state != AL_PLAYING && playing)
			{
				if (loop)
				{
					Play();
				}
				else
				{
					playing = false;
				}
			}
		}
	}
}