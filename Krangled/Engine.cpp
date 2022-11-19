#include "Engine.h"
#include "SceneManager.h";
#include <string>
#include "Scene.h"
#include "GameObject.h"

void Engine::Init()
{
	std::shared_ptr<Scene> pScene = std::make_shared<Scene>(std::string{ "TestScene" });
	std::shared_ptr<GameObject> pTestObject = std::make_shared<GameObject>();

	pScene->AddGameObject(pTestObject);
	SceneManager::GetInstance().AddScene(pScene);
}

void Engine::Run()
{

	bool running = true;

	// In the future we will have a better way to end the application, for now we just close the console window
	while (running)
	{
		// Right now the fixed update is not fixed, I will fix this once a time class is implemented
		SceneManager::GetInstance().GetCurrentScene()->FixedUpdate();
		SceneManager::GetInstance().GetCurrentScene()->Update();

	}
}

void Engine::Clean()
{
}
