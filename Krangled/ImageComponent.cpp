#include "ImageComponent.h"
#include "SDL.h"
#include "Renderer.h"
#include "Texture.h"
#include "SDL_image.h"

KREN::ImageComponent::ImageComponent(Texture* pTex)
	: m_pTexture{ pTex }
{
}

void KREN::ImageComponent::Render()
{
	SDL_RenderCopy(Renderer::GetInstance().GetRenderer(), m_pTexture->GetTexture(), nullptr, nullptr);
}
