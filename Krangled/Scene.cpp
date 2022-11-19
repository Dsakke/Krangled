#include "Scene.h"
#include "GameObject.h"

Scene::Scene(const std::string& name, SceneVector pObjects)
	: m_Name{ name }
	, m_pGameObjects{ pObjects }
{
}

Scene::Scene(const Scene& scene)
	: m_Name{ scene.m_Name }
	, m_pGameObjects{ scene.m_pGameObjects.size(), std::allocator<std::shared_ptr<GameObject>>{} }
{
	// Make a deep copy of the vector
	for (size_t i{}; i < scene.m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i] = std::make_shared<GameObject>(*(scene.m_pGameObjects[i]));
	}
}

Scene::Scene(Scene&& scene) noexcept
	: m_Name{ std::move(scene.m_Name) }
	, m_pGameObjects{ std::move(scene.m_pGameObjects) }
{
}

Scene& Scene::operator=(const Scene& scene)
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

Scene& Scene::operator=(Scene&& scene) noexcept
{
	m_Name = std::move(scene.m_Name);
	m_pGameObjects = std::move(scene.m_pGameObjects);
	return *this;
}



void Scene::Setname(const std::string& name)
{
	m_Name = name;
}

void Scene::Update()
{
	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->Update();
	}
}

void Scene::FixedUpdate()
{
	for (size_t i{}; i < m_pGameObjects.size(); ++i)
	{
		m_pGameObjects[i]->FixedUpdate();
	}
}

void Scene::AddGameObject(std::shared_ptr<GameObject> pObj)
{
	m_pGameObjects.push_back(pObj);
}
