#pragma once
#include <memory>
#include "KRKeyCodes.h"
namespace KREN
{
	class ICommand;
	class InputAction final
	{
	public:
		InputAction(std::unique_ptr<ICommand>&& pCommand, KeyCode keyCode);
		InputAction(InputAction&& other) = default;
		InputAction& operator=(InputAction&& other) = default;

		_NODISCARD ICommand& GetCommand() const;
		void SetCommand(std::unique_ptr<ICommand>&& pCommand);
		_NODISCARD KeyCode GetKeyCode() const;
		void SetKeyCode(KeyCode keyCode);
		void Execute(); 

		// deleted functions
		InputAction(const InputAction&) = delete;
		InputAction& operator=(const InputAction&) = delete;
	protected:
		std::unique_ptr<ICommand> m_pCommand;
		KeyCode m_KeyCode;

	};
}
