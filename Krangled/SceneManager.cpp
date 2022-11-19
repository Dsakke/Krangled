#include "SceneManager.h"
#include "Scene.h"
#include <string>

void SceneManager::AddScene(std::shared_ptr<Scene> scene)
{
	m_Scenes.push_back(scene);
}

inline std::shared_ptr<Scene> SceneManager::GetScene(const std::string& name)
{
	auto pred = [=](const std::shared_ptr<Scene>& pScene)
	{
		return pScene->GetName() == name;
	};

	auto it = std::find_if(m_Scenes.begin(), m_Scenes.end(), pred);

	return it == m_Scenes.end() ? std::shared_ptr<Scene>{} : *it;
}

inline const std::shared_ptr<Scene> SceneManager::GetScene(const std::string& name) const
{
	auto pred = [=](const std::shared_ptr<Scene>& pScene)
	{
		return pScene->GetName() == name;
	};

	auto it = std::find_if(m_Scenes.begin(), m_Scenes.end(), pred);

	return it == m_Scenes.end() ? std::shared_ptr<Scene>{} : *it;
}

inline std::shared_ptr<Scene> SceneManager::GetScene(size_t idx)
{
	return idx < m_Scenes.size() ? m_Scenes[idx] : std::shared_ptr<Scene>{};
}

inline const std::shared_ptr<Scene> SceneManager::GetScene(size_t idx) const
{
	return idx < m_Scenes.size() ? m_Scenes[idx] : std::shared_ptr<Scene>{};
}

inline std::shared_ptr<Scene> SceneManager::GetCurrentScene()
{
	return m_pCurrentScene;
}

inline const std::shared_ptr<Scene> SceneManager::GetCurrentScene() const
{
	return m_pCurrentScene;
}

void SceneManager::SetCurrentScene(size_t idx)
{
	m_pCurrentScene = idx < m_Scenes.size() ? m_Scenes[idx] : m_pCurrentScene;
}

void SceneManager::SetCurrentScene(const std::string& name)
{
	std::shared_ptr<Scene> pScene = GetScene(name);
	if (pScene)
	{
		m_pCurrentScene = pScene;
	}
}

