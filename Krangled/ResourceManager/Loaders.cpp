#include "Loaders.h"
#include "SDL.h"
#include "SDL_image.h"
#include "..\Rendering\Renderer.h"
#include "..\Logger\Logger.h"
#include "..\Rendering\SDLRenderer.h"
#include "..\Image\Texture.h"
#include <print>

std::shared_ptr<KREN::Texture> KREN::KRInternal::LoadImage(const std::string& path)
{
	SDL_Surface* pSurf = IMG_Load(path.c_str());

	if (!pSurf)
	{
		std::string str = IMG_GetError();
		Logger::LogError("IMG_Load: " + str);
	}

	SDL_Texture* pTex = SDL_CreateTextureFromSurface(std::dynamic_pointer_cast<SDLRenderer>(Renderer::GetInstance().m_pRenderer)->m_pRenderer, pSurf);
	if (!pTex)
	{
		const char* errorMsg = SDL_GetError();
		Logger::LogError("SDL_CreateTextureFromSurface: " + *errorMsg);
	}
	return std::make_shared<Texture>(Texture{ pTex });
}
