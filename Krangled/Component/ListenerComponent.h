#pragma once
#include "Component.h"
#include"../../KrangledMath/KrangledMath/KRMath/KRMath.h"


namespace KREN
{
	class Transform;
	class ListenerComponent final : public Component
	{
	public:
		ListenerComponent();
		ListenerComponent(float gain);

		void SetGain(float gain);

		void Start() override;
		void Update() override;
	private:
		void SetListernerPosition(const KRM::FVector3& position);

		std::weak_ptr<Transform> m_pTransform;
		float m_Gain;
	};
}