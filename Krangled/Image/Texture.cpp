#include "Texture.h"
#include "SDL.h"

KREN::Texture::Texture(SDL_Texture* pSurface)
	: m_pSurface{pSurface}
{
}

KRM::Vector<int, 2> KREN::Texture::GetDimensions() const
{
	KRM::Vector<int, 2> dimensions{};
	SDL_QueryTexture(m_pSurface, nullptr, nullptr, &dimensions.x, &dimensions.y);

	return dimensions;
}

SDL_Texture* KREN::Texture::GetTexture() const
{
	return m_pSurface;
}


