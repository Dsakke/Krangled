#include "ImageComponent.h"
#include "SDL.h"
#include "Renderer.h"
#include "Texture.h"
#include "SDL_image.h"
#include "Transform.h"
#include "GameObject.h"

KREN::ImageComponent::ImageComponent(Texture* pTex)
	: m_pTexture{ pTex }
{
}

void KREN::ImageComponent::Render()
{
	SDL_Texture* pTexture = m_pTexture->GetTexture();
	SDL_Rect destRect{};
	SDL_QueryTexture(pTexture, nullptr, nullptr, &destRect.w, &destRect.h);

	std::shared_ptr<GameObject> pOwner = GetOwner().lock();
	std::shared_ptr<Transform> trans = pOwner->GetComponent<KREN::Transform>().lock();
	KRM::FVector3 pos = trans->GetPosition();
	destRect.x = (int)pos.x;
	destRect.y = (int)pos.y;

	SDL_RenderCopy(Renderer::GetInstance().GetRenderer(), pTexture, nullptr, &destRect);
}
