#include "SDLRenderer.h"
#include "SDL.h"
#include "Texture.h"

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
	SDL_Rect rect{};
	rect.x = destRect.x;
	rect.y = destRect.y;
	rect.w = destRect.width;
	rect.h = destRect.height;

	SDL_RenderCopy(m_pRenderer, pTexture.lock()->GetTexture(), nullptr, &rect);
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
