#pragma once
#include "Component.h"
#include <memory>
class Texture;

namespace KREN
{
	class ImageComponent final : public Component
	{
	public:
		ImageComponent(Texture* pTex);

		void Render() override;
	private:
		Texture* m_pTexture;
	};
}