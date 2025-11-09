#pragma once
#include "../ICommand.h"
#include <memory>

namespace KREN
{
	class Audio;
	class AudioSource;
}

class PlaySoundCommand final : public KREN::ICommand
{
public:
	PlaySoundCommand(std::weak_ptr<KREN::AudioSource> pAudioSource);
	void Execute() override;

private:
	std::weak_ptr<KREN::AudioSource> m_pAudioSource;
};