#pragma once
#include <memory>
#include "../GameObject/GameObject.h"

namespace KREN
{
	class Component : public std::enable_shared_from_this<Component>
	{
	public:
		virtual ~Component() = default;

		// Called before first update of the object in a scene
		virtual void Start() {}

		// Happens every frame
		virtual void Update() {}

		// Update that happens after a fixed amount of time
		virtual void FixedUpdate() {}

		// Happens after Update, put any code to do with rendering here
		virtual void Render() {}

		std::weak_ptr<GameObject> GetOwner();


		void SetOwner(std::weak_ptr<GameObject> pNewOwner);
	private:
		friend void GameObject::Start();

		bool HasStarted = false;
		std::weak_ptr<GameObject> m_pOwner;
	};
}