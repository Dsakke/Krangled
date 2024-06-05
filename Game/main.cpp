#pragma once
#include "Engine.h"
#include "Logger.h"
int main()
{
	KREN::Engine engine{};

	engine.Init();
	engine.Run();
	engine.Clean();
	return 0;
}