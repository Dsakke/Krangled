#include "Transform.h"

void KREN::Transform::SetPosition(const KRM::FVector3& pos)
{
    m_Position = pos;
}


KRM::FVector3 KREN::Transform::GetPosition()
{
    return m_Position;
}

void KREN::Transform::SetScale(const KRM::FVector2& scale)
{
    m_Scale = scale;
}

KRM::FVector2 KREN::Transform::GetScale()
{
    return m_Scale;
}
