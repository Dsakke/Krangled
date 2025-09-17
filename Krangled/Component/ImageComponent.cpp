#include "ImageComponent.h"
#include "SDL.h"
#include "..\Rendering\Renderer.h"
#include "..\Image\Texture.h"
#include "SDL_image.h"
#include "Transform.h"
#include "..\GameObject\GameObject.h"
#include "KRMath.h"

KREN::ImageComponent::ImageComponent(std::shared_ptr<Texture> pTex)
	: m_pTexture{ pTex }
{
}

void KREN::ImageComponent::Render()
{
	std::shared_ptr<GameObject> pOwner = GetOwner().lock();
	std::shared_ptr<Transform> trans = pOwner->GetComponent<KREN::Transform>().lock();
	KRM::FVector3 pos = trans->GetPosition();
	KRM::Vector<int, 2> size = m_pTexture->GetDimensions();
	KRM::IRect rect{ (int)pos.x , (int)pos.y, size.x, size.y };

	Renderer::GetInstance().RenderTexture(m_pTexture, rect);
}
