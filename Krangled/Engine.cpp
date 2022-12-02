#include "Engine.h"
#include "SceneManager.h";
#include <string>
#include "Scene.h"
#include "GameObject.h"
#include "Time.h"
#include "SDL.h"
#include "Renderer.h"
#include "SquareRenderComp.h"

void KREN::Engine::Init()
{
	// Test Scene setup
	std::shared_ptr<Scene> pScene = std::make_shared<Scene>(std::string{ "TestScene" });
	std::shared_ptr<GameObject> pTestObject = std::make_shared<GameObject>();
	pTestObject->AddComponent(std::make_shared<SquareRenderComp>());

	pScene->AddGameObject(pTestObject);
	SceneManager::GetInstance().AddScene(pScene);
	SceneManager::GetInstance().SetCurrentScene(0);

	Renderer::GetInstance().Init();
}

void KREN::Engine::Run()
{

	bool running = true;

	// In the future we will have a better way to end the application, for now we just close the console window
	while (running)
	{
		Time::GetInstance().UpdateTime();
		std::shared_ptr<Scene> currentScene = SceneManager::GetInstance().GetCurrentScene();
		m_FixedUpdateTimer += Time::GetInstance().GetElapsedTime();
		if (m_FixedUpdateTimer >= m_FixedUpdateInterval)
		{
			currentScene->FixedUpdate();
		}
		currentScene->Update();
		currentScene->Render();
		Renderer::GetInstance().Render();
	}
}

void KREN::Engine::Clean()
{
}

