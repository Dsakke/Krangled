#pragma once
#include <vector>
#include <memory>
#include <string>

namespace KREN
{
	class Component;
	class GameObject final : public std::enable_shared_from_this<GameObject>
	{
	public:
		GameObject() : m_pComponents{} {};
		GameObject(const GameObject& gameObj);
		GameObject(GameObject&& gameObj) noexcept;
		GameObject& operator=(const GameObject& gameObj);
		GameObject& operator=(GameObject&& gameObj) noexcept;

		~GameObject() = default;
		void AddComponent(const std::shared_ptr<Component>& pComp);
		void AddComponent(std::shared_ptr<Component>&& pComp);

		void Start();
		void Update();
		void FixedUpdate();
		void Render();

		// Will return the first component found of the specified type
		template<class T>
		_NODISCARD std::weak_ptr<T> GetComponent();

		// Will return all the components of type
		template<class T>
		_NODISCARD std::vector<std::weak_ptr<T>> GetComponents();

		void RemoveComponent(std::weak_ptr<KREN::Component> component);
	private:

		// shared pointer because even though this should be the only owner 
		// other objects still need to be able to refference the components
		std::vector<std::shared_ptr<Component>> m_pComponents;
	};

	template<class T>
	inline std::weak_ptr<T> GameObject::GetComponent()
	{
		for (int i{}; i < m_pComponents.size(); ++i)
		{
			std::shared_ptr<T> pShrd = std::dynamic_pointer_cast<T>(m_pComponents[i]);
			if (pShrd)
			{
				return std::weak_ptr<T>{ pShrd };
			}
		}

		return std::weak_ptr<T>{};
	}

	template<class T>
	inline std::vector<std::weak_ptr<T>> GameObject::GetComponents()
	{
		std::vector<std::weak_ptr<T>> vec{};
		for (int i{}; i < m_pComponents.size(); ++i)
		{
			std::shared_ptr<T> pShrd = std::dynamic_pointer_cast<T>(m_pComponents[i]);
			if (pShrd)
			{
				vec.push_back(std::weak_ptr<T>{ pShrd });
			}
		}
		return vec;
	}
}
