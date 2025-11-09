#pragma once
#include "IRenderer.h"
#include <memory>
#include "KRMath.h"
#include <string>
#include "../ResourceManager/Loaders.h"

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
namespace KREN
{
	class Texture;
	namespace KRInternal
	{
		class SDLRenderer final : public IRenderer
		{
		public:
			void Init() override;
			void Render() override;
			void RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::IRect& destRect) override;
			void RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::Vector<int, 2>& position) override;
			void RenderTexture(std::weak_ptr<Texture> pTexture, int x, int y, int width, int height) override;

		private:
			friend std::shared_ptr<KREN::Texture> Loader::LoadImage(const std::string& path);

			SDL_Window* m_pWindow;
			SDL_Renderer* m_pRenderer;
		};
	}
}
