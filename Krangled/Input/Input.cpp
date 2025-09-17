#include "Input.h"
#include "IInputManager.h"
#include "..\Settings.h"
#ifdef SDL_INPUT
#include "SDLInputManager.h"
#endif 

KREN::Input::Input()
{
#ifdef SDL_INPUT
	m_InputManager = std::make_shared<SDLInputManager>();
#endif 	
}

std::weak_ptr<KREN::IInputManager> KREN::Input::GetInputManager()
{
	return std::weak_ptr<KREN::IInputManager>{ m_InputManager };
}
