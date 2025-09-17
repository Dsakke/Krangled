#pragma once
#include "..\Krangled\Engine\Engine.h"

int main()
{
	KREN::Engine engine{};

	engine.Init();
	engine.Run();
	engine.Clean();
	return 0;
}