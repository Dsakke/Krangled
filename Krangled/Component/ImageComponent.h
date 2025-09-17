#pragma once
#include "Component.h"
#include <memory>
#include "KRMath.h"

namespace KREN
{
	class Texture;
	class ImageComponent final : public Component
	{
	public:
		ImageComponent(std::shared_ptr<Texture> pTex);

		void Render() override;
	private:
		std::shared_ptr<Texture> m_pTexture;
	};
}