#include "GameObject.h"
#include "..\Component\Component.h"

KREN::GameObject::GameObject(const GameObject& gameObj)
	: m_pComponents{ gameObj.m_pComponents }
{
}

KREN::GameObject::GameObject(GameObject&& gameObj) noexcept
	: m_pComponents{ std::move(gameObj.m_pComponents) }
{
}

KREN::GameObject& KREN::GameObject::operator=(const GameObject& gameObj)
{
	m_pComponents = gameObj.m_pComponents;

	return *this;
}

KREN::GameObject& KREN::GameObject::operator=(GameObject&& gameObj) noexcept
{
	gameObj.m_pComponents = std::move(gameObj.m_pComponents);

	return *this;
}

void KREN::GameObject::AddComponent(const std::shared_ptr<Component>& pComp)
{
	m_pComponents.push_back(pComp);
	pComp->SetOwner(weak_from_this());
}

void KREN::GameObject::AddComponent(std::shared_ptr<Component>&& pComp)
{
	m_pComponents.push_back( pComp );
	pComp->SetOwner(weak_from_this());
}

void KREN::GameObject::Start()
{
	for (size_t i{}; i < m_pComponents.size(); ++i) 
	{
		if (!m_pComponents[i]->HasStarted) // TODO this should be better, an additional loop over all components will be detrimental to performance
		{
			m_pComponents[i]->Update();
		}
	}
}

void KREN::GameObject::Update()
{
	for (size_t i{}; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Update();
	}
}

void KREN::GameObject::FixedUpdate()
{
	for (size_t i{}; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->FixedUpdate();
	}
}

void KREN::GameObject::Render()
{
	for (size_t i{}; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Render();
	}
}

void KREN::GameObject::RemoveComponent(std::weak_ptr<KREN::Component> pComponent)
{
	auto it = std::find(m_pComponents.begin(), m_pComponents.end(), pComponent.lock());
	if (it != m_pComponents.end())
	{
		m_pComponents.erase(it);
	}
}
