#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(const GameObject& gameObj)
	: m_pComponents{ gameObj.m_pComponents }
{
}

GameObject::GameObject(GameObject&& gameObj) noexcept
	: m_pComponents{ std::move(gameObj.m_pComponents) }
{
}

GameObject& GameObject::operator=(const GameObject& gameObj)
{
	m_pComponents = gameObj.m_pComponents;

	return *this;
}

GameObject& GameObject::operator=(GameObject&& gameObj) noexcept
{
	gameObj.m_pComponents = std::move(gameObj.m_pComponents);

	return *this;
}

void GameObject::AddComponent(const std::shared_ptr<Component>& pComp)
{
	m_pComponents.push_back(pComp);
}

void GameObject::AddComponent(std::shared_ptr<Component>&& pComp)
{
	m_pComponents.push_back( pComp );
}



void GameObject::Update()
{
	for (size_t i{}; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Update();
	}
}

void GameObject::FixedUpdate()
{
	for (size_t i{}; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->FixedUpdate();
	}
}
