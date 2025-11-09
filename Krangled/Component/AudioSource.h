#pragma once 
#include "Component.h"
#include <memory>

namespace KREN
{
	class Audio;
	class Transform;
	class AudioSource final : public Component
	{
	public:
		AudioSource();
		~AudioSource();
		AudioSource(const AudioSource&) = delete;
		AudioSource(AudioSource&&) = delete;
		AudioSource& operator=(const AudioSource&) = delete;
		AudioSource& operator=(AudioSource&&) = delete;


		void PlaySound();

		void Start() override;
		void Update() override;

		void SetPitch(float pitch);
		void SetGain(float gain);
		void SetMaxDistance(float maxDistance);
		void SetRollOffFactor(float factor);
		void SetOuterConeGain(float outerCone);
		void SetInnerConeGain(float innerCone);
		void SetReferenceDistance(float distance);
		void SetIsLooping(bool isLooping);
		void SetSound(std::shared_ptr<Audio> pAudio);
	private:
		class ImplAudioSource;

		std::unique_ptr<ImplAudioSource> m_pImplAudioSource;
		std::weak_ptr<Transform> m_pTransform;
	};
}