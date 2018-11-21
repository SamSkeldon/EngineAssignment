#include "Audio.h"
#include <iostream>
#include <AL/al.h>
#include <vorbis/vorbisfile.h>
#include <vector>

namespace myengine
{
	struct AudioCreate
	{
		ALuint id;
		
		~AudioCreate()
		{
			alDeleteBuffers(1, &id);
		}
		//loads the ogg file 
		void load_ogg(std::string filename, std::vector<char> &buffer, ALenum &format, ALsizei &freq)
		{
			int endian = 0; 
			int bitStream = 0;
			long bytes = 0;
			char soundArray[2048] = {0};
			vorbis_info *info = NULL;
			OggVorbis_File oggFile = {0};

			if (ov_fopen(filename.c_str(), &oggFile) != 0)
			{
				std::cout << filename << " couldnt be opened" << std::endl;
				throw std::exception();
			}

			info = ov_info(&oggFile, -1);

			if (info->channels == 1)
			{
				format = AL_FORMAT_MONO16;
			}
			else
			{
				format = AL_FORMAT_STEREO16;
			}

			freq = info->rate;

			while (true)
			{
				bytes = ov_read(&oggFile, soundArray, 2048, endian, 2, 1, &bitStream);
				if (bytes < 0)
				{
					ov_clear(&oggFile);
					std::cout << filename << " decoding failed" << std::endl;
					throw std::exception();
				}
				else if (bytes == 0)
				{
					break;
				}
				buffer.insert(buffer.end(), soundArray, soundArray + bytes);
			}
			ov_clear(&oggFile);
		}
	};

	Audio::Audio(){}

	Audio::Audio(std::string path)
	{
		load(path);
	}

	void Audio::load(std::string path)
	{
		create = std::make_shared<AudioCreate>();
		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;
		alGenBuffers(1, &create->id);
		create->load_ogg(path.c_str(), bufferData, format, freq);
		alBufferData(create->id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);
	}

	//the audios location within the scene 
	void Audio::play()
	{
		ALuint audioId = 0;
		alGenSources(1, &audioId);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(audioId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(audioId, AL_BUFFER, create->id);
		alSourcePlay(audioId);
	}

	//takes the audios details and sets it to be able to be played. 
	void Audio::play(float volume, float varMin, float varMax)
	{
		varMin*= 1000.0f;
		varMax*= 1000.0f;
		float variance = (std::rand() % ((int)varMin + 1 - (int)varMax) + (int)varMin)/1000.0f;

		ALuint audioId = 0;
		alGenSources(1, &audioId);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(audioId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(audioId, AL_BUFFER, create->id);
		alSourcef(audioId, AL_PITCH, variance);
		alSourcef(audioId, AL_GAIN, volume);
		alSourcePlay(audioId);
	}
}
