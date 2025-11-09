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
#include "..\Component\AudioSource.h"
#include "..\Component\ListenerComponent.h"
#include "..\Input\InputAction.h"
#include "..\Input\PlaySoundCommand.h"
#include "..\Audio\AudioManager.h"

void KREN::Engine::Init()
{
	Renderer::GetInstance().Init();

	Logger::ChangeService(std::make_unique<ConsoleLogger>());

	::KRInternal::AudioManager::GetInstance();
	// Test Scene setup
	std::shared_ptr<Scene> pScene = std::make_shared<Scene>(std::string{ "TestScene" });
	std::shared_ptr<GameObject> pTestObject = std::make_shared<GameObject>();
	std::shared_ptr<Transform> pTransform = std::make_shared<Transform>();
	std::shared_ptr<ImageComponent> pImageComponent = std::make_shared<ImageComponent>(ResourceManager::GetInstance().GetResource<Texture>("Resources\\Test.png"));
	pTestObject->AddComponent(pImageComponent);
	pTestObject->AddComponent(pTransform);

	std::shared_ptr<AudioSource> pAudioSource = std::make_shared<AudioSource>();
	std::shared_ptr<Audio> pAudio = ResourceManager::GetInstance().GetResource<KREN::Audio>("Resources\\test.wav");
	pAudioSource->SetSound(pAudio);
	pAudioSource->SetIsLooping(false);
	std::shared_ptr<ListenerComponent> pListener = std::make_shared<ListenerComponent>();

	pTestObject->AddComponent(pAudioSource);
	pTestObject->AddComponent(pListener);


	std::shared_ptr<IInputManager> pInputManager = Input::GetInstance().GetInputManager().lock();

	InputAction playSoundAction{ std::move(std::make_unique<PlaySoundCommand>(pAudioSource)), KeyCode::f };
	pInputManager->AddButtonUpAction(std::move(playSoundAction));

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

