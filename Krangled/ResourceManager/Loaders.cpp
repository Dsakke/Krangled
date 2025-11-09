#include "Loaders.h"
#include "SDL.h"
#include "SDL_image.h"
#include "..\Rendering\Renderer.h"
#include "..\Logger\Logger.h"
#include "..\Rendering\SDLRenderer.h"
#include "..\Image\Texture.h"
#include <print>
#include "..\Audio\Audio.h"
#include <fstream>
#include <algorithm>
#include "..\Utilities\StringUtilities.h"
#include <cstring>
#include <iostream>

std::shared_ptr<KREN::Texture> KREN::KRInternal::Loader::LoadImage(const std::string& path)
{
	SDL_Surface* pSurf = IMG_Load(path.c_str());

	if (!pSurf)
	{
		std::string str = IMG_GetError();
		Logger::LogError("IMG_Load: " + str);
	}

	SDL_Texture* pTex = SDL_CreateTextureFromSurface(std::dynamic_pointer_cast<SDLRenderer>(Renderer::GetInstance().m_pRenderer)->m_pRenderer, pSurf);
	if (!pTex)
	{
		const char* errorMsg = SDL_GetError();
		Logger::LogError("SDL_CreateTextureFromSurface: " + *errorMsg);
	}
	return std::make_shared<Texture>(Texture{ pTex });
}

std::shared_ptr<KREN::Audio> KREN::KRInternal::Loader::LoadAudio(const std::string& path)
{
	size_t formatStringOffset = path.find_last_of('.');
	std::string format = path.substr(formatStringOffset + 1);
	
	std::fstream stream = std::fstream(path, std::ios_base::binary | std::ios_base::in);
	std::shared_ptr<Audio> result;
	if (StringUtilities::CompareIgnoreCase(format, "wav"))
	{
		result = LoadWavToAudio(stream);
	}
	else
	{
		Logger::LogError("Tried loading" + path + "No loader exists for " + format);
	}

	stream.close();
	return result;
}


// Based on the format described at http://soundfile.sapp.org/doc/WaveFormat/
std::shared_ptr<KREN::Audio> KREN::KRInternal::Loader::LoadWavToAudio(std::fstream& stream)
{
	char tempBuffer[5]{};
	tempBuffer[4] = '\0';
	stream.read(tempBuffer, 4);
	
	if (strcmp(tempBuffer, "RIFF") != 0)
	{
		return std::shared_ptr<KREN::Audio>();
	}

	Uint32 fileSize;
	stream.read(reinterpret_cast<char*>(&fileSize), 4);

	stream.read(tempBuffer, 4);
	if (strcmp(tempBuffer, "WAVE") != 0)
	{
		return std::shared_ptr<KREN::Audio>();
	}

	stream.read(tempBuffer, 4);
	if (strcmp(tempBuffer, "fmt ") != 0)
	{
		return std::shared_ptr<KREN::Audio>();
	}

	Uint32 formatChunkSize;
	stream.read(reinterpret_cast<char*>(&formatChunkSize), 4);

	Uint16 audioFormat;
	stream.read(reinterpret_cast<char*>(&audioFormat), 2);

	Uint16 numberOfChannels;
	stream.read(reinterpret_cast<char*>(&numberOfChannels), 2);

	Uint32 sampleRate;
	stream.read(reinterpret_cast<char*>(&sampleRate), 4);

	Uint32 byteRate;
	stream.read(reinterpret_cast<char*>(&byteRate), 4);

	Uint16 byteAllignment;
	stream.read(reinterpret_cast<char*>(&byteAllignment), 2);

	Uint16 bitsPerSample;
	stream.read(reinterpret_cast<char*>(&bitsPerSample), 2);

	bool isDataChunk = false;
	
	while (!isDataChunk && !stream.eof())
	{
		char tempBuffer0[5];
		tempBuffer0[4] = '\0';
		stream.read(reinterpret_cast<char*>(&tempBuffer0), 4);


		Uint32 chunkSize{};
		stream.read(reinterpret_cast<char*>(&chunkSize), 4);
		isDataChunk = strcmp(tempBuffer0, "data") == 0;
		if (!isDataChunk)
		{
			stream.ignore(chunkSize);
			continue;
		}

		char* pData = new char[chunkSize];
		stream.read(pData, chunkSize);

		return std::make_shared<Audio>(audioFormat, numberOfChannels, sampleRate, byteRate, bitsPerSample, chunkSize, pData);
	}

	return std::shared_ptr<KREN::Audio>();
}
