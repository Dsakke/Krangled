#pragma once
#include <memory>
#include "Singleton.h"

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
namespace KREN
{
	class Renderer final : public Singleton<Renderer>
	{
	public:
		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) = delete;

		_NODISCARD SDL_Renderer* GetRenderer();

		void Init();
		void Render();
	private:
		Renderer() = default;
		friend class Singleton<Renderer>;

		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
	
	};
}