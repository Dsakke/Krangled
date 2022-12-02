#include "Renderer.h"
#include "SDL.h"

SDL_Renderer* KREN::Renderer::GetRenderer()
{
	return m_pRenderer;
}

void KREN::Renderer::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_pWindow = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);


}

void KREN::Renderer::Render()
{
	SDL_RenderPresent(m_pRenderer);
	SDL_RenderClear(m_pRenderer);
}
