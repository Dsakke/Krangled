#include "Input.h"
#include "SDL.h"
#include "Command.h"

void KREN::Input::AddButtonDownAction(const InputAction& action)
{
	m_DownInputActions.insert(std::pair<SDL_KeyCode, InputAction>{action.GetKeyCode(), action});
}

void KREN::Input::AddButtonUpAction(const InputAction& action)
{
	m_UpInputActions.insert(std::pair<SDL_KeyCode, InputAction>{action.GetKeyCode(), action});
}

void KREN::Input::SetQuitCommand(std::shared_ptr<Command> pQuitCommand)
{
	m_pQuitCommand = pQuitCommand;
}

void KREN::Input::UpdateInput()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			m_pQuitCommand->Do();
			break;
		case SDL_KEYDOWN:
		case SDL_MOUSEBUTTONDOWN:
		{
			auto range = m_DownInputActions.equal_range((SDL_KeyCode)sdlEvent.key.keysym.scancode);
			for (; range.first != range.second; ++range.first)
			{
				range.first->second.Do();
			}
			break;
		}
		case SDL_KEYUP:
		case SDL_MOUSEBUTTONUP:
		{
			auto range = m_UpInputActions.equal_range((SDL_KeyCode)sdlEvent.key.keysym.scancode);
			for (; range.first != range.second; ++range.first)
			{
				range.first->second.Do();
			}
			break;
		}
		default:
			break;
		}
	}
}

KREN::Input::Input()
{ }

KREN::InputAction::InputAction(SDL_KeyCode keyCode, const std::shared_ptr<Command>& command)
	: m_KeyCode{ keyCode }
	, m_pCommand{ command }
{
}

std::shared_ptr<KREN::Command> KREN::InputAction::GetCommand()
{
	return m_pCommand;
}

void KREN::InputAction::SetCommand(std::shared_ptr<Command> pCommand)
{
	m_pCommand = pCommand;
}

SDL_KeyCode KREN::InputAction::GetKeyCode() const
{
	return m_KeyCode;
}

void KREN::InputAction::SetKeyCode(SDL_KeyCode keyCode)
{
	m_KeyCode = keyCode;
}

void KREN::InputAction::Do()
{
	m_pCommand->Do();
}


