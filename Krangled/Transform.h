#pragma once
#include "Component.h"
#include <KRMath.h>

namespace KREN
{
	// TODO: add move setters
	class Transform : public Component
	{
	public:
		Transform() = default;

		void SetPosition(const KRM::FVector3& pos);
		KRM::FVector3 GetPosition();

		void SetScale(const KRM::FVector2& scale);
		KRM::FVector2 GetScale();
	private:
		KRM::FVector3 m_Position;
		KRM::FVector2 m_Scale;
	};
}