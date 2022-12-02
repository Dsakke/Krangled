#include "SquareRenderComp.h"
#include "SDL.h"
#include "Renderer.h"

void KREN::SquareRenderComp::Render()
{

    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

    SDL_SetRenderDrawColor(Renderer::GetInstance().GetRenderer(), 0, 0, 255, 255);
	SDL_RenderFillRect(Renderer::GetInstance().GetRenderer(), &rect);
}
