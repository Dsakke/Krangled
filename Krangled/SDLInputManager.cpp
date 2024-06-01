#include "SDLInputManager.h"
#include "SDL.h"
#include "ICommand.h"
#include "SDL_scancode.h"
#include "SDL_keycode.h"

using KeyCode = KREN::KeyCode;

static std::unordered_map<SDL_Keycode, KeyCode> KEYCODEMAP
{
	{SDLK_RETURN, KeyCode::Return},
	{SDLK_ESCAPE, KeyCode::Escape},
	{SDLK_BACKSPACE, KeyCode::BackSpace },
	{SDLK_TAB, KeyCode::Tab},
	{SDLK_SPACE, KeyCode::Space},
	{SDLK_EXCLAIM, KeyCode::Exclaim},
	{SDLK_QUOTEDBL, KeyCode::DoubleQuotes},
	{SDLK_HASH, KeyCode::Hashtag},
	{SDLK_PERCENT, KeyCode::Percent},
	{SDLK_DOLLAR, KeyCode::Dollar},
	{SDLK_AMPERSAND, KeyCode::Ampersand},
	{SDLK_QUOTE, KeyCode::Quote},
	{SDLK_LEFTPAREN, KeyCode::LeftParenthese},
	{SDLK_RIGHTPAREN, KeyCode::RightParenthese},
	{SDLK_ASTERISK, KeyCode::Asterisk},
	{SDLK_PLUS, KeyCode::Plus},
	{SDLK_COMMA, KeyCode::Comma},
	{SDLK_MINUS, KeyCode::Minus},
	{SDLK_PERIOD, KeyCode::Period},
	{SDLK_SLASH, KeyCode::Slash},
	{SDLK_0, KeyCode::Zero},
	{SDLK_1, KeyCode::One},
	{SDLK_2, KeyCode::Two},
	{SDLK_3, KeyCode::Three},
	{SDLK_4, KeyCode::Four},
	{SDLK_5, KeyCode::Five},
	{SDLK_6, KeyCode::Six},
	{SDLK_7, KeyCode::Seven},
	{SDLK_8, KeyCode::Eight},
	{SDLK_9, KeyCode::Nine},
	{SDLK_COLON, KeyCode::Colon},
	{SDLK_SEMICOLON, KeyCode::SemiColon},
	{SDLK_LESS, KeyCode::LessThan},
	{SDLK_GREATER, KeyCode::GreaterThan},
	{SDLK_QUESTION, KeyCode::QuestionMark},
	{SDLK_AT, KeyCode::At},
	{SDLK_LEFTBRACKET, KeyCode::LeftBracket},
	{SDLK_RIGHTBRACKET, KeyCode::RightBracket},
	{SDLK_BACKSLASH, KeyCode::BackSlash},
	{SDLK_CARET, KeyCode::Caret},
	{SDLK_UNDERSCORE, KeyCode::UnderScore},
	{SDLK_BACKQUOTE, KeyCode::BackQoute},
	{SDLK_a, KeyCode::a},
	{SDLK_b, KeyCode::b},
	{SDLK_c, KeyCode::c},
	{SDLK_d, KeyCode::d},
	{SDLK_e, KeyCode::e},
	{SDLK_f, KeyCode::f},
	{SDLK_g, KeyCode::g},
	{SDLK_h, KeyCode::h},
	{SDLK_i, KeyCode::i},
	{SDLK_j, KeyCode::j},
	{SDLK_k, KeyCode::k},
	{SDLK_l, KeyCode::l},
	{SDLK_m, KeyCode::m},
	{SDLK_n, KeyCode::n},
	{SDLK_o, KeyCode::o},
	{SDLK_p, KeyCode::p},
	{SDLK_q, KeyCode::q},
	{SDLK_r, KeyCode::r},
	{SDLK_s, KeyCode::s},
	{SDLK_t, KeyCode::t},
	{SDLK_u, KeyCode::u},
	{SDLK_v, KeyCode::v},
	{SDLK_w, KeyCode::w},
	{SDLK_x, KeyCode::x},
	{SDLK_y, KeyCode::y},
	{SDLK_z, KeyCode::z},
	{SDLK_CAPSLOCK, KeyCode::CapsLock},
	{SDLK_F1, KeyCode::F1},
	{SDLK_F2, KeyCode::F2},
	{SDLK_F3, KeyCode::F3},
	{SDLK_F4, KeyCode::F4},
	{SDLK_F5, KeyCode::F5},
	{SDLK_F6, KeyCode::F6},
	{SDLK_F7, KeyCode::F7},
	{SDLK_F8, KeyCode::F8},
	{SDLK_F9, KeyCode::F9},
	{SDLK_F10, KeyCode::F10},
	{SDLK_F11, KeyCode::F11},
	{SDLK_F12, KeyCode::F12},
	{KMOD_LCTRL, KeyCode::LCTRL},
	{KMOD_LSHIFT, KeyCode::LShift},
	{KMOD_LALT, KeyCode::LALT},
	{KMOD_RCTRL, KeyCode::RCTRL},
	{KMOD_RSHIFT, KeyCode::RShift},
	{KMOD_RALT, KeyCode::RAlt}
};

void KREN::SDLInputManager::AddButtonDownAction(InputAction&& action)
{
	m_DownInputActions.emplace(std::make_pair<KeyCode, InputAction>(action.GetKeyCode(), std::move(action)));
}

void KREN::SDLInputManager::AddButtonUpAction(InputAction&& action)
{
	m_UpInputActions.emplace(std::make_pair<KeyCode, InputAction>(action.GetKeyCode(), std::move(action)));
}

void KREN::SDLInputManager::SetQuitCommand(std::shared_ptr<ICommand> pQuitCommand)
{
	m_pQuitCommand = pQuitCommand;
}

void KREN::SDLInputManager::UpdateInput() 
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			m_pQuitCommand->Execute();
			break;
		case SDL_KEYDOWN:
		case SDL_MOUSEBUTTONDOWN:
		{
			auto range = m_DownInputActions.equal_range(KEYCODEMAP[sdlEvent.key.keysym.sym]);
			for (; range.first != range.second; ++range.first)
			{
				range.first->second.Execute();
			}
			break;
		}
		case SDL_KEYUP:
		case SDL_MOUSEBUTTONUP:
		{
			auto range = m_UpInputActions.equal_range(KEYCODEMAP[sdlEvent.key.keysym.sym]);
			for (; range.first != range.second; ++range.first)
			{
				range.first->second.Execute();
			}
			break;
		}
		default:
			break;
		}
	}
}

KREN::SDLInputManager::~SDLInputManager()
{
}




