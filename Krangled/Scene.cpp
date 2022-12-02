#include "Scene.h"
#include "GameObject.h"

KREN::Scene::Scene(const std::string& name, SceneVector pObjects)
	: m_Name{ name }
	, m_pGameObjects{ pObjects }
{
}

KREN::Scene::Scene(const Scene& scene)
	: m_Name{ scene.m_Name }
	, m_pGameObjects{ scene.m_pGameObjects.size(), std::allocator<std::shared_ptr<GameObject>>{} }
{
	// Make a deep copy of the vector
	for (size_t i{}; i < scene.m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i] = std::make_shared<GameObject>(*(scene.m_pGameObjects[i]));
	}
}

KREN::Scene::Scene(Scene&& scene) noexcept
	: m_Name{ std::move(scene.m_Name) }
	, m_pGameObjects{ std::move(scene.m_pGameObjects) }
{
}

KREN::Scene& KREN::Scene::operator=(const Scene& scene)
{
	m_Name = scene.m_Name;
	m_pGameObjects.resize(scene.m_pGameObjects.size());

	// Make a deep copy of the vector
	for (size_t i{}; i < scene.m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i] = std::make_shared<GameObject>(*(scene.m_pGameObjects[i]));
	}
	return *this;
}

KREN::Scene& KREN::Scene::operator=(Scene&& scene) noexcept
{
	m_Name = std::move(scene.m_Name);
	m_pGameObjects = std::move(scene.m_pGameObjects);
	return *this;
}



void KREN::Scene::Setname(const std::string& name)
{
	m_Name = name;
}

void KREN::Scene::Update()
{
	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->Update();
	}
}

void KREN::Scene::FixedUpdate()
{
	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->FixedUpdate();
	}
}

void KREN::Scene::Render()
{
	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->Render();
	}
}

void KREN::Scene::AddGameObject(std::shared_ptr<GameObject> pObj)
{
	m_pGameObjects.push_back(pObj);
}
