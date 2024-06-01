#pragma once
#include <memory>
#include "Singleton.h"

namespace KREN
{
	class InputAction;
	class ICommand;
	class IInputManager
	{
	public:
		virtual void AddButtonDownAction(InputAction&& action) = 0;
		virtual void AddButtonUpAction(InputAction&& action) = 0;
		virtual void SetQuitCommand(std::shared_ptr<ICommand> pQuitCommand) = 0;
		virtual void UpdateInput() = 0;
	protected:
		IInputManager() = default;

		virtual ~IInputManager() = default;

		IInputManager(const IInputManager&) = delete;
		IInputManager(IInputManager&&) = delete;
		IInputManager& operator=(const IInputManager&) = delete;
		IInputManager& operator=(IInputManager&&) = delete;

	};
}