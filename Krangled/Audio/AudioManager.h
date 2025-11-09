#pragma once
#include "../Singleton.h"
#include <string>
#include "Audio.h"

class ALCdevice;
class ALCcontext;

namespace KRInternal
{
	class AudioManager final : public KREN::Singleton<AudioManager>
	{
	private:
		class PImplAudioManager;
	public:
		~AudioManager(); // needs to exist because PImplAudioManager can only be deleted in the cpp
	private:
		AudioManager();
		friend class KREN::Singleton<AudioManager>;

		std::unique_ptr<PImplAudioManager> m_pImplAudioManager;

	};
}