#pragma once
#include "..\Singleton.h"
#include <vector>
#include <string>

namespace KREN
{
	class Scene; 
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		SceneManager(const SceneManager&) = delete;
		SceneManager(SceneManager&&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;
		SceneManager& operator=(SceneManager&&) = delete;


		void AddScene(std::shared_ptr<Scene> scene);

		_NODISCARD std::shared_ptr<Scene> GetScene(const std::string& name);
		_NODISCARD const std::shared_ptr<Scene> GetScene(const std::string& name) const;
		_NODISCARD std::shared_ptr<Scene> GetScene(size_t idx);
		_NODISCARD const std::shared_ptr<Scene> GetScene(size_t idx) const;
		_NODISCARD std::shared_ptr<Scene> GetCurrentScene();
		_NODISCARD const std::shared_ptr<Scene> GetCurrentScene() const;

		void SetCurrentScene(size_t idx);
		void SetCurrentScene(const std::string& name);
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
	
		std::shared_ptr<Scene> m_pCurrentScene;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
	};
}