#pragma once
#include <memory>
#include "..\ResourceManager\Loaders.h"
#include <SDL_stdinc.h>


namespace KREN
{
	class Audio final 
	{
	public:

		Audio(Audio&&) = delete;
		Audio(const Audio&) = delete;
		Audio& operator=(Audio&&) = delete;
		Audio& operator=(const Audio&) = delete;

		~Audio();

		Uint16 GetAudioFormat() const;
		Uint16 GetNumberOfChannels() const;
		Uint32 GetSampleRate() const;
		Uint32 GetByteRate() const;
		Uint16 GetBitsPerSample() const;
		Uint32 GetDataSize() const;
		const char* GetData() const;

		Audio(Uint16 audioFormat, Uint16 numberOfChannels, Uint32 sampleRate, Uint32 byteRate, Uint16 bitsPerSample, Uint32 dataSize, char* pData);

	private:
		friend class KRInternal::Loader;


		Uint16 m_AudioFormat;
		Uint16 m_NumberOfChannels;
		Uint32 m_SampleRate;
		Uint32 m_ByteRate;
		Uint16 m_BitsPerSample;
		Uint32 m_DataSize;
		char* m_pData = nullptr;


	};
}