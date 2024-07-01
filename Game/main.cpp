#pragma once
#include "Engine.h"
#include "Logger.h"
#include "Scene.h"
#include <GameObject.h>
#include <Transform.h>
#include <ImageComponent.h>
#include <ResourceManager.h>
#include <SceneManager.h>
#include <IInputManager.h>
#include <MoveCommand.h>
#include <Input.h>
#include <KRKeyCodes.h>

int main()
{
	KREN::Engine engine{};

	engine.Init();
	engine.Run();
	engine.Clean();
	return 0;
}

void SetupTestScene()
{
	// Test Scene setup
	std::shared_ptr<KREN::Scene> pScene = std::make_shared<KREN::Scene>(std::string{ "TestScene" });
	std::shared_ptr<KREN::GameObject> pTestObject = std::make_shared<KREN::GameObject>();
	std::shared_ptr<KREN::Transform> pTransform = std::make_shared<KREN::Transform>();
	std::shared_ptr<KREN::ImageComponent> pImageComponent = std::make_shared<KREN::ImageComponent>(KREN::ResourceManager::GetInstance().GetResource<KREN::Texture>("Resources\\Test.png"));
	pTestObject->AddComponent(pImageComponent);
	pTestObject->AddComponent(pTransform);

	std::shared_ptr<KREN::IInputManager> pInputManager = KREN::Input::GetInstance().GetInputManager().lock();
	pInputManager->AddButtonDownAction(KREN::InputAction{ std::make_unique<MoveCommand>(pTransform), KREN::KeyCode::w });


	pScene->AddGameObject(pTestObject);
	KREN::SceneManager::GetInstance().AddScene(pScene);
	KREN::SceneManager::GetInstance().SetCurrentScene(0);

}