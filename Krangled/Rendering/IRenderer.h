#pragma once
#include <memory>
#include "KRMath.h"
namespace KREN
{
	class Texture;

	class IRenderer
	{
	public:
		virtual ~IRenderer() = default;

		virtual void Init() = 0;
		virtual void Render() = 0;
		virtual void RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::IRect& destRect) = 0;
		virtual void RenderTexture(std::weak_ptr<Texture> pTexture, int x, int y, int width, int height) = 0;
		virtual void RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::Vector<int, 2>& position) = 0;

	private:
	};
}