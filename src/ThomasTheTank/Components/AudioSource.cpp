#include "AudioSource.h"
#include <stdexcept>
#include "../Entity.h"
#include "Transform.h"
#include <iostream>

#include "stb_vorbis.c"
namespace ThomasTheTank
{

	static void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer,
		ALenum& _format, ALsizei& _freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_path.c_str(),
			&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			//_format = AL_FORMAT_STEREO16;
			_format = AL_FORMAT_MONO16;
		}

		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		_buffer.resize(samples * channels * sizeof(short));
		memcpy(&_buffer.at(0), output, _buffer.size());

		// Record the sample rate required by OpenAL
		_freq = sampleRate;

		// Clean up the read data
		free(output);
	}

	AudioSource::AudioSource()
	{
		m_format = 0;
		m_freq = 0;
		std::vector<unsigned char> bufferData;
		load_ogg("../data/dixie_horn.ogg", bufferData, m_format, m_freq);

		m_bufferId = 0;
		alGenBuffers(1, &m_bufferId);

		alBufferData(m_bufferId, m_format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), m_freq);

		alGenSources(1, &m_sourceId);

		alSourcei(m_sourceId, AL_BUFFER, m_bufferId);
	}

	AudioSource::AudioSource(std::string _path)
	{
		m_format = 0;
		m_freq = 0;
		std::vector<unsigned char> bufferData;
		load_ogg(_path.c_str(), bufferData, m_format, m_freq);

		m_bufferId = 0;
		alGenBuffers(1, &m_bufferId);

		alBufferData(m_bufferId, m_format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), m_freq);

		alGenSources(1, &m_sourceId);

		alSourcei(m_sourceId, AL_BUFFER, m_bufferId);
	}

	void AudioSource::Play()
	{
		alSourcePlay(m_sourceId);
	}

	void AudioSource::onTick()
	{
		vec3 temp = getEntity()->getTransform()->getPosition();
		//std::cout << temp.x << " " << temp.y << " " << temp.z << std::endl;
		alSource3f(m_sourceId, AL_POSITION, temp.x, temp.y, temp.z);
		alSourcef(m_sourceId, AL_PITCH, 2);
		//alSourcef(sourceId, AL_GAIN, vol);

		int state = 0;
		alGetSourcei(m_sourceId, AL_SOURCE_STATE, &state);

		if (loop && state != AL_PLAYING)
		{
			//Play();
		}
	}

	void AudioSource::onInitialize()
	{
		//Play();
	}

	void AudioSource::onDestroy()
	{
		alDeleteSources(1, &m_sourceId);
		alDeleteBuffers(1, &m_bufferId);
	}
}