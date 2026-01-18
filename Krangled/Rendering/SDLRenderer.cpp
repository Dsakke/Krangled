#include "SDLRenderer.h"
#include "SDL.h"
#include "..\Image\Texture.h"

void KREN::KRInternal::SDLRenderer::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_pWindow = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
}

void KREN::KRInternal::SDLRenderer::Render()
{
	SDL_RenderPresent(m_pRenderer);
	SDL_RenderClear(m_pRenderer);
}

void KREN::KRInternal::SDLRenderer::RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::IRect& destRect)
{
	std::shared_ptr<Texture> pSharedTexture = pTexture.lock();

	if (pSharedTexture)
	{
		KRM::Vector<int, 2> dimensions = pSharedTexture->GetDimensions();
		KRM::IRect sourceRect{0,0, dimensions.x, dimensions.y};
		RenderTexture(pTexture, sourceRect, destRect);
	}
}

void KREN::KRInternal::SDLRenderer::RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::Vector<int, 2>& position)
{
	SDL_Texture* pSDLTexture = pTexture.lock()->GetTexture();
	int width, height;
	SDL_QueryTexture(pSDLTexture, nullptr, nullptr, &width, &height);

	RenderTexture(pTexture, position.x, position.y, width, height);
}

void KREN::KRInternal::SDLRenderer::RenderTexture(std::weak_ptr<Texture> pTexture, int x, int y, int width, int height)
{
	RenderTexture(pTexture, KRM::IRect{ x, y, width, height });
}

void KREN::KRInternal::SDLRenderer::RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::IRect& destRect, const KRM::IRect& sourceRect)
{
	SDL_Rect sdlDestRect{};
	sdlDestRect.x = destRect.x;
	sdlDestRect.y = destRect.y;
	sdlDestRect.w = destRect.width;
	sdlDestRect.h = destRect.height;

	SDL_Rect sdlSourceRect{};
	sdlSourceRect.x = destRect.x;
	sdlSourceRect.y = destRect.y;
	sdlSourceRect.w = destRect.width;
	sdlSourceRect.h = destRect.height;

	SDL_RenderCopy(m_pRenderer, pTexture.lock()->GetTexture(), &sdlSourceRect, &sdlDestRect);
}
