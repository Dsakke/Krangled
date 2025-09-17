#include "Engine.h"
#include "..\Scene\SceneManager.h"
#include <string>
#include "..\Scene\Scene.h"
#include "..\GameObject\GameObject.h"
#include "..\Time\KRTime.h"
#include "SDL.h"
#include "..\Rendering\Renderer.h"
#include "..\Component\ImageComponent.h"
#include "..\Input\IInputManager.h"
#include "..\Input\Input.h"
#include "..\ICommand.h"
#include "..\QuitCommand.h"
#include "..\ResourceManager\ResourceManager.h"
#include "..\Image\Texture.h"
#include "..\Logger\ConsoleLogger.h"
#include "..\Component\Transform.h"
#include "..\Input\InputAction.h"

void KREN::Engine::Init()
{
	Renderer::GetInstance().Init();

	Logger::ChangeService(std::make_unique<ConsoleLogger>());

	// Test Scene setup
	std::shared_ptr<Scene> pScene = std::make_shared<Scene>(std::string{ "TestScene" });
	std::shared_ptr<GameObject> pTestObject = std::make_shared<GameObject>();
	std::shared_ptr<Transform> pTransform = std::make_shared<Transform>();
	std::shared_ptr<ImageComponent> pImageComponent = std::make_shared<ImageComponent>(ResourceManager::GetInstance().GetResource<Texture>("Resources\\Test.png"));
	pTestObject->AddComponent(pImageComponent);
	pTestObject->AddComponent(pTransform);

	std::shared_ptr<IInputManager> pInputManager = Input::GetInstance().GetInputManager().lock();


	pScene->AddGameObject(pTestObject);
	SceneManager::GetInstance().AddScene(pScene);
	SceneManager::GetInstance().SetCurrentScene(0);

}

void KREN::Engine::Run()
{

	bool running = true;
	std::shared_ptr<QuitCommand> pQuitCommand{ std::make_shared<QuitCommand>(running) };
	Input::GetInstance().GetInputManager().lock()->SetQuitCommand(pQuitCommand);

	// In the future we will have a better way to end the application, for now we just close the console window
	while (running)
	{
		KRTime::GetInstance().UpdateTime();
		Input::GetInstance().GetInputManager().lock()->UpdateInput();
		std::shared_ptr<Scene> currentScene = SceneManager::GetInstance().GetCurrentScene();
		m_FixedUpdateTimer += KRTime::GetInstance().GetElapsedTime();
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

