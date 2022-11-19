#include "Engine.h"

int main()
{
	Engine engine{};

	engine.Init();
	engine.Run();
	engine.Clean();
	return 0;
}