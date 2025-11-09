#include "../Settings.h"
#include "AudioSource.h"
#include "../Audio/AudioManager.h"
#include <al.h>
#include <KRMath.h>
#include "Transform.h"

class KREN::AudioSource::ImplAudioSource
{
#ifdef OPEN_AL
public:
	ImplAudioSource()
	{
		alGenSources(1, &m_SourceIdx);
		alGenBuffers(1, &m_BufferIdx);
	}

	void SetPitch(float pitch)
	{
		alSourcef(m_SourceIdx, AL_PITCH, (ALfloat)pitch);
	}

	void SetGain(float gain)
	{
		alSourcef(m_SourceIdx, AL_GAIN, (ALfloat)gain);
	}

	void SetMaxDistance(float maxDistance)
	{
		alSourcef(m_SourceIdx, AL_MAX_DISTANCE, (ALfloat)maxDistance);
	}

	void SetRollOffFactor(float factor)
	{
		alSourcef(m_SourceIdx, AL_ROLLOFF_FACTOR, factor);
	}

	void SetOuterConeGain(float outerCone)
	{
		alSourcef(m_SourceIdx, AL_CONE_OUTER_GAIN, (ALfloat)outerCone);
	}

	void SetInnerConeGain(float innerCone)
	{
		alSourcef(m_SourceIdx, AL_CONE_OUTER_GAIN, (ALfloat)innerCone);
	}

	void SetReferenceDistance(float distance)
	{
		alSourcef(m_SourceIdx, AL_REFERENCE_DISTANCE, (ALfloat)distance);
	}

	void SetIsLooping(bool isLooping)
	{
		alSourcei(m_SourceIdx, AL_LOOPING, isLooping ? AL_TRUE : AL_FALSE);
	}

	void PlaySound()
	{
		alSourcePlay(m_SourceIdx);
	}

	void SetSound(std::shared_ptr<Audio> pAudio)
	{
		Uint64 format;
		if (pAudio->GetNumberOfChannels() > 1)
		{
			format = pAudio->GetBitsPerSample() == 16 ? AL_FORMAT_STEREO16 : AL_FORMAT_STEREO8;
		}
		else
		{
			format = pAudio->GetBitsPerSample() == 16 ? AL_FORMAT_MONO16 : AL_FORMAT_MONO8;
		}
		alGetError();
		alBufferData(m_BufferIdx, format, pAudio->GetData(), (ALsizei)(pAudio->GetDataSize()), (ALsizei)(pAudio->GetSampleRate()));
		ALenum error = alGetError();
		alSourceQueueBuffers(m_SourceIdx, 1, &m_BufferIdx);
		error = alGetError();
	}

	void SetPosition(const KRM::FVector3& position)
	{
		
	}

	~ImplAudioSource()
	{
		alDeleteSources(1, &m_SourceIdx);
		DestroyBuffer();
	}
private:
	ALuint m_SourceIdx;
	ALuint m_BufferIdx;


	void DestroyBuffer()
	{
		alDeleteBuffers(1, &m_BufferIdx);
	}

#endif 
};

KREN::AudioSource::AudioSource()
{
	m_pImplAudioSource = std::make_unique<ImplAudioSource>();
}

KREN::AudioSource::~AudioSource()
{

}

void KREN::AudioSource::Start()
{
	m_pTransform = GetOwner().lock()->GetComponent<Transform>();
}

void KREN::AudioSource::Update()
{
	std::shared_ptr<Transform> pTransform = m_pTransform.lock();
	if (pTransform)
	{
		m_pImplAudioSource->SetPosition(pTransform->GetPosition());
	}
}

void KREN::AudioSource::PlaySound()
{
	m_pImplAudioSource->PlaySound();
}

void KREN::AudioSource::SetPitch(float pitch)
{
	m_pImplAudioSource->SetPitch(pitch);
}

void KREN::AudioSource::SetGain(float gain)
{
	m_pImplAudioSource->SetGain(gain);
}

void KREN::AudioSource::SetMaxDistance(float maxDistance)
{
	m_pImplAudioSource->SetMaxDistance(maxDistance);
}

void KREN::AudioSource::SetRollOffFactor(float factor)
{
	m_pImplAudioSource->SetRollOffFactor(factor);
}

void KREN::AudioSource::SetOuterConeGain(float outerCone)
{
	m_pImplAudioSource->SetOuterConeGain(outerCone);
}

void KREN::AudioSource::SetInnerConeGain(float innerCone)
{
	m_pImplAudioSource->SetInnerConeGain(innerCone);
}

void KREN::AudioSource::SetIsLooping(bool isLooping)
{
	m_pImplAudioSource->SetIsLooping(isLooping);
}

void KREN::AudioSource::SetSound(std::shared_ptr<Audio> pAudio)
{
	m_pImplAudioSource->SetSound(pAudio);
}

