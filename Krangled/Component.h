#pragma once
#include <memory>
namespace KREN
{
	class GameObject;
	class Component : std::enable_shared_from_this<Component>
	{
	public:
		virtual ~Component() = default;

		// Called on creation of the object
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

		std::weak_ptr<GameObject> m_pOwner;
	};
}