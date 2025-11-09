#include "PlaySoundCommand.h"
#include "../Component/AudioSource.h"

PlaySoundCommand::PlaySoundCommand(std::weak_ptr<KREN::AudioSource> pAudioSource)
	: m_pAudioSource{ pAudioSource }
{
}

void PlaySoundCommand::Execute()
{
	std::shared_ptr<KREN::AudioSource> pAudioSource = m_pAudioSource.lock();
	if (pAudioSource)
	{
		pAudioSource->PlaySound();
	}
}
