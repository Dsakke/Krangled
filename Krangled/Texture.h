#pragma once
#include <memory>

struct SDL_Texture;
class Texture
{
public:
	Texture(SDL_Texture* pSurface);

	SDL_Texture* GetTexture() const;
private:
	SDL_Texture* m_pSurface;
};