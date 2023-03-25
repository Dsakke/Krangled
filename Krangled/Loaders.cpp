#include "Loaders.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Renderer.h"
#include "Logger.h"

Texture* KREN::KRInternal::LoadImage(const std::string& path)
{
	SDL_Surface* pSurf = IMG_Load(path.c_str());
	if (!pSurf)
	{
		Logger::LogError("IMG_Load: %s\n" + *IMG_GetError());
	}

	SDL_Texture* pTex = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetRenderer(), pSurf);
	if (!pTex)
	{
		const char* errorMsg = SDL_GetError();
		Logger::LogError("SDL_CreateTextureFromSurface: " + *errorMsg);
	}
	return new Texture(pTex);
}
