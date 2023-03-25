#include "Texture.h"

Texture::Texture(SDL_Texture* pSurface)
	: m_pSurface{pSurface}
{
}

SDL_Texture* Texture::GetTexture() const
{
	return m_pSurface;
}
