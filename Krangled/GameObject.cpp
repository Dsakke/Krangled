#include "GameObject.h"
#include "Component.h"

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
}

void KREN::GameObject::AddComponent(std::shared_ptr<Component>&& pComp)
{
	m_pComponents.push_back( pComp );
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
