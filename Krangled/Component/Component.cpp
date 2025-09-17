#include "Component.h"
#include "..\GameObject\GameObject.h"

std::weak_ptr<KREN::GameObject> KREN::Component::GetOwner()
{
    return m_pOwner;
}

void KREN::Component::SetOwner(std::weak_ptr<GameObject> pNewOwner)
{
    if (!m_pOwner.expired())
    {
        std::shared_ptr<GameObject> pOwner = m_pOwner.lock();
        pOwner->RemoveComponent(weak_from_this());
    }

    m_pOwner = pNewOwner;
}
