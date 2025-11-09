#include "Audio.h"

KREN::Audio::Audio(
	Uint16 audioFormat,
	Uint16 numberOfChannels,
	Uint32 sampleRate,
	Uint32 byteRate,
	Uint16 bitsPerSample,
	Uint32 dataSize,
	char* pData)
	: m_AudioFormat(audioFormat)
	, m_NumberOfChannels{ numberOfChannels }
	, m_SampleRate{ sampleRate }
	, m_ByteRate{ byteRate }
	, m_BitsPerSample{ bitsPerSample }
	, m_DataSize{ dataSize }
	, m_pData{ pData }

{

}


KREN::Audio::~Audio()
{
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
}

Uint16 KREN::Audio::GetAudioFormat() const
{
	return m_AudioFormat;
}

Uint16 KREN::Audio::GetNumberOfChannels() const
{
	return m_NumberOfChannels;
}

Uint32 KREN::Audio::GetSampleRate() const
{
	return m_SampleRate;
}

Uint32 KREN::Audio::GetByteRate() const
{
	return m_ByteRate;
}

Uint16 KREN::Audio::GetBitsPerSample() const
{
	return m_BitsPerSample;
}

Uint32 KREN::Audio::GetDataSize() const
{
	return m_DataSize;
}

const char* KREN::Audio::GetData() const
{
	return static_cast<const char*>(m_pData);
}
