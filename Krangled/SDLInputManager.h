#pragma once
#include "Singleton.h"
#include <memory>
#include <unordered_map>

#include "InputAction.h"
#include "KRKeyCodes.h"
#include "IInputManager.h"
#include "InputAction.h"
#include "ICommand.h"

union SDL_Event;
namespace KREN
{
	class ICommand;
	class SDLInputManager final : public IInputManager
	{
		//static std::unordered_map<SDL_Keycode, KeyCode> KEYCODEMAP;

	public:
		SDLInputManager() = default;
		SDLInputManager(const SDLInputManager&) = delete;
		SDLInputManager(SDLInputManager&&) = delete;
		SDLInputManager& operator=(const SDLInputManager&) = delete;
		SDLInputManager& operator=(SDLInputManager&&) = delete;
		void AddButtonDownAction(InputAction&& action) override;
		void AddButtonUpAction(InputAction&& action) override;
		void SetQuitCommand(std::shared_ptr<ICommand> pQuitCommand) override;
		void UpdateInput() override;

		~SDLInputManager();
	private:

		std::shared_ptr<ICommand> m_pQuitCommand;
		std::unordered_multimap<KeyCode, InputAction> m_DownInputActions;
		std::unordered_multimap<KeyCode, InputAction> m_UpInputActions;
	};
}