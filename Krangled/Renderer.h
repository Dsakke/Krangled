#pragma once
#include <memory>
#include "Singleton.h"
#include "KRMath.h"
#include "Loaders.h"
namespace KREN
{
	class Texture;
	class IRenderer;
	class Renderer final : public Singleton<Renderer>
	{
	public:
		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) = delete;

		void Init();
		void Render();
		void RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::IRect& destRect);
		void RenderTexture(std::weak_ptr<Texture> pTexture, const KRM::Vector<int, 2>& position);
		void RenderTexture(std::weak_ptr<Texture> pTexture, int x, int y, int width, int height);



		~Renderer();
	private:
		Renderer();
		friend class Singleton<Renderer>;
		friend std::shared_ptr<KREN::Texture> KREN::KRInternal::LoadImage(const std::string& path); // this is bad

		std::shared_ptr<IRenderer> m_pRenderer;
	};
}