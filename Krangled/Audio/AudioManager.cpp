#include "..\Settings.h"
#include "AudioManager.h"
#include <al.h>
#include <alc.h>
#include <alext.h>
#include "..\Logger\Logger.h"
#include <ResourceManager/ResourceManager.h>
#include "Audio.h"

namespace KRInternal
{
	class AudioManager::PImplAudioManager
	{
	public:
		PImplAudioManager()
		{
			m_pDevice = alcOpenDevice(nullptr);
			ALenum error = alcGetError(m_pDevice);

			if (m_pDevice)
			{
				m_pContext = alcCreateContext(m_pDevice, NULL);
				error = alcGetError(m_pDevice);
				alcMakeContextCurrent(m_pContext);
				error = alcGetError(m_pDevice);
			}
		}

		~PImplAudioManager()
		{
			alcDestroyContext(m_pContext);
			m_pContext = nullptr;
			alcCloseDevice(m_pDevice);
			m_pDevice = nullptr;
		}
	private:

		ALCdevice* m_pDevice;
		ALCcontext* m_pContext;
	};
}

KRInternal::AudioManager::AudioManager()
	: m_pImplAudioManager{ std::make_unique<PImplAudioManager>() }
{
}

KRInternal::AudioManager::~AudioManager()
{

}