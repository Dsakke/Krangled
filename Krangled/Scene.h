#pragma once
#include <vector>
#include <string>
#include <memory>

class GameObject;
class Scene final
{
public:
	using SceneVector = std::vector<std::shared_ptr<GameObject>>;

	Scene(const std::string& name, SceneVector pObjects = SceneVector{});
	Scene(const Scene& scene);
	Scene(Scene&& scene) noexcept;
	Scene& operator=(const Scene& scene);
	Scene& operator=(Scene&& scene) noexcept;

	inline const std::string& GetName() const { return m_Name; }
	void Setname(const std::string& name);

	void Update();
	void FixedUpdate();

	void AddGameObject(std::shared_ptr<GameObject> pObj);

private:
	std::string m_Name;

	SceneVector m_pGameObjects;
};
