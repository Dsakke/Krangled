#pragma once

namespace KREN
{
	class Component
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
	private:
	};
}