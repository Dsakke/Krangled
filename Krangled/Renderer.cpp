#include "Renderer.h"
#include "Settings.h"
#include "IRenderer.h"
#ifdef SDL_RENDERING
#include "SDLRenderer.h"
#endif 

void KREN::Renderer::Init()
{
#ifdef SDL_RENDERING
	if (!m_pRenderer)
	{
		m_pRenderer = std::make_shared<KRInternal::SDLRenderer>();
	}
#endif 
	m_pRenderer->Init();
}

void KREN::Renderer::Render()
{
	m_pRenderer->Render();
}

void KREN::Renderer::RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::IRect& destRect)
{
	m_pRenderer->RenderTexture(pTexture, destRect);
}

void KREN::Renderer::RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::Vector<int, 2>& position)
{
	m_pRenderer->RenderTexture(pTexture, position);
}

void KREN::Renderer::RenderTexture(std::weak_ptr<Texture> pTexture, int x, int y, int width, int height)
{
	m_pRenderer->RenderTexture(pTexture, x, y, width, height);
}

KREN::Renderer::~Renderer()
{
}

KREN::Renderer::Renderer()
{
}