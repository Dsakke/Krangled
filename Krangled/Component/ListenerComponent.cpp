#include "ListenerComponent.h"
#include "../GameObject/GameObject.h"
#include "Transform.h"
#include <al.h>

KREN::ListenerComponent::ListenerComponent()
	: m_Gain{ 0.f }
{
}

KREN::ListenerComponent::ListenerComponent(float gain)
	: m_Gain{ gain }
{
}

void KREN::ListenerComponent::SetGain(float gain)
{
	m_Gain = gain;
}

void KREN::ListenerComponent::Start()
{
	auto pOwner = GetOwner().lock();

	if (pOwner)
	{
		m_pTransform = pOwner->GetComponent<Transform>();
		auto pTransform = m_pTransform.lock();
		if (pTransform)
		{
			SetListernerPosition(pTransform->GetPosition());
		}
	}
}

void KREN::ListenerComponent::Update()
{
	auto pTransform = m_pTransform.lock();
	if (pTransform)
	{
		SetListernerPosition(pTransform->GetPosition());
	}
}

void KREN::ListenerComponent::SetListernerPosition(const KRM::FVector3& position)
{
	alListener3f(AL_POSITION, position.x, position.y, position.z);
}


