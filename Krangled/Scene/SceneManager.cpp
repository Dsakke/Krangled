#include "SceneManager.h"
#include "Scene.h"
#include <string>
#include "..\Logger\Logger.h"

void KREN::SceneManager::AddScene(std::shared_ptr<Scene> scene)
{
	m_Scenes.push_back(scene);
}

std::shared_ptr<KREN::Scene> KREN::SceneManager::GetScene(const std::string& name)
{
	auto pred = [=](const std::shared_ptr<Scene>& pScene)
	{
		return pScene->GetName() == name;
	};

	auto it = std::find_if(m_Scenes.begin(), m_Scenes.end(), pred);

	return it == m_Scenes.end() ? std::shared_ptr<Scene>{} : *it;
}

const std::shared_ptr<KREN::Scene> KREN::SceneManager::GetScene(const std::string& name) const
{
	auto pred = [=](const std::shared_ptr<Scene>& pScene)
	{
		return pScene->GetName() == name;
	};

	auto it = std::find_if(m_Scenes.begin(), m_Scenes.end(), pred);

	return it == m_Scenes.end() ? std::shared_ptr<Scene>{} : *it;
}

 std::shared_ptr<KREN::Scene> KREN::SceneManager::GetScene(size_t idx)
{
	if (idx < m_Scenes.size())
	{
		return m_Scenes[idx];
	}

	return std::shared_ptr<Scene>{};
}

 const std::shared_ptr<KREN::Scene> KREN::SceneManager::GetScene(size_t idx) const
{
	if (idx < m_Scenes.size())
	{
		return m_Scenes[idx];
	}

	return std::shared_ptr<Scene>{};
}

std::shared_ptr<KREN::Scene> KREN::SceneManager::GetCurrentScene()
{
	return m_pCurrentScene;
}

const std::shared_ptr<KREN::Scene> KREN::SceneManager::GetCurrentScene() const
{
	return m_pCurrentScene;
}

void KREN::SceneManager::SetCurrentScene(size_t idx)
{
	if (idx < m_Scenes.size())
	{
		m_pCurrentScene = m_Scenes[idx];
		return;
	}

	Logger::LogWarning("SceneManager::SetCurrentScene >> Tried to set a non-existant scene as currentScene");
}

void KREN::SceneManager::SetCurrentScene(const std::string& name)
{
	std::shared_ptr<Scene> pScene = GetScene(name);
	if (pScene)
	{
		m_pCurrentScene = pScene;
		return;
	}

	Logger::LogWarning("SceneManager::SetCurrentScene >> Tried to set a non-existant scene as currentScene");
}

