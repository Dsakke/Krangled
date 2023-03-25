#include "Engine.h"
#include "SceneManager.h"
#include <string>
#include "Scene.h"
#include "GameObject.h"
#include "Time.h"
#include "SDL.h"
#include "Renderer.h"
#include "ImageComponent.h"
#include "Input.h"
#include "Command.h"
#include "QuitCommand.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "ConsoleLogger.h"

void KREN::Engine::Init()
{
	Renderer::GetInstance().Init();

	Logger::ChangeService(std::make_unique<ConsoleLogger>());
	// Test Scene setup
	std::shared_ptr<Scene> pScene = std::make_shared<Scene>(std::string{ "TestScene" });
	std::shared_ptr<GameObject> pTestObject = std::make_shared<GameObject>();
	std::shared_ptr<ImageComponent> pImageComponent = std::make_shared<ImageComponent>(ResourceManager::GetInstance().GetResource<Texture>("Resources\\Test.png"));
	pTestObject->AddComponent(pImageComponent);

	pScene->AddGameObject(pTestObject);
	SceneManager::GetInstance().AddScene(pScene);
	SceneManager::GetInstance().SetCurrentScene(0);

}

void KREN::Engine::Run()
{

	bool running = true;
	std::shared_ptr<QuitCommand> pQuitCommand{ std::make_shared<QuitCommand>(running) };
	Input::GetInstance().SetQuitCommand(pQuitCommand);

	// In the future we will have a better way to end the application, for now we just close the console window
	while (running)
	{
		Time::GetInstance().UpdateTime();
		Input::GetInstance().UpdateInput();
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

