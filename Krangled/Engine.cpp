#include "Engine.h"
#include "SceneManager.h"
#include <string>
#include "Scene.h"
#include "GameObject.h"
#include "Time.h"
#include "SDL.h"
#include "Renderer.h"
#include "ImageComponent.h"
#include "IInputManager.h"
#include "Input.h"
#include "ICommand.h"
#include "QuitCommand.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "ConsoleLogger.h"
#include "Transform.h"
#include "InputAction.h"
#include "MoveCommand.h"

void KREN::Engine::Init()
{
	Renderer::GetInstance().Init();

	Logger::ChangeService(std::make_unique<ConsoleLogger>());


}

void KREN::Engine::Run()
{

	bool running = true;
	std::shared_ptr<QuitCommand> pQuitCommand{ std::make_shared<QuitCommand>(running) };
	Input::GetInstance().GetInputManager().lock()->SetQuitCommand(pQuitCommand);

	// In the future we will have a better way to end the application, for now we just close the console window
	while (running)
	{
		Time::GetInstance().UpdateTime();
		Input::GetInstance().GetInputManager().lock()->UpdateInput();
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

