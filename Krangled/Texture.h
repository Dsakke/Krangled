#pragma once
#include <memory>
#include "KRMath.h"
#include "Loaders.h"

struct SDL_Texture;
namespace KREN
{
	class Texture
	{
	public:
		KRM::Vector<int, 2> GetDimensions() const;

		SDL_Texture* GetTexture() const;
	private:
		friend std::shared_ptr<Texture> KRInternal::LoadImage(const std::string& path);

		SDL_Texture* m_pSurface;
		Texture(SDL_Texture* pSurface);
	};
}