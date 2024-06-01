#pragma once
#include "Singleton.h"
#include <memory>

namespace KREN
{
	class IInputManager;
	class Input final : public Singleton<Input>
	{
	public:
		std::weak_ptr<IInputManager> GetInputManager();

	private:
		std::shared_ptr<IInputManager> m_InputManager;

		friend class Singleton<Input>;
		Input();
		Input(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator==(const Input&) = delete;
		Input& operator==(Input&&) = delete;
	};
}