#pragma once
#include "Singleton.h"
#include <memory>
#include <unordered_map>
#include "SDL_scancode.h"
#include "SDL_keycode.h"

union SDL_Event;
namespace KREN
{
	class Command;
	class InputAction final
	{
	public:
		InputAction(SDL_KeyCode keyCode, const std::shared_ptr<Command>& command);

		_NODISCARD std::shared_ptr<Command> GetCommand();
		void SetCommand(std::shared_ptr<Command> pCommand);
		_NODISCARD SDL_KeyCode GetKeyCode() const;
		void SetKeyCode(SDL_KeyCode keyCode);
		void Do();
	private:
		SDL_KeyCode m_KeyCode;
		std::shared_ptr<Command> m_pCommand;
	};

	class Input final : public Singleton<Input>
	{
	public:
		Input(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator=(const Input&) = delete;
		Input& operator=(Input&&) = delete;
		void AddButtonDownAction(const InputAction& action);
		void AddButtonUpAction(const InputAction& action);
		void SetQuitCommand(std::shared_ptr<Command> pQuitCommand);
		void UpdateInput();
	private:
		Input();

		friend class Singleton<Input>;
		std::shared_ptr<Command> m_pQuitCommand;
		std::unordered_multimap<SDL_KeyCode, InputAction> m_DownInputActions;
		std::unordered_multimap<SDL_KeyCode, InputAction> m_UpInputActions;
	};
}