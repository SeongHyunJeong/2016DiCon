#include "SceneManager.h"



SceneManager::SceneManager()
{
	currentScene = nullptr;
}


SceneManager::~SceneManager()
{
	if(currentScene!=nullptr)
	delete currentScene;
}

void SceneManager::Render()
{
	currentScene->Render();
}

void SceneManager::Update(float dTime)
{
	currentScene->Update(dTime);
}

void SceneManager::ChangeScene(Scene*scene)
{
	if (currentScene != nullptr)
		delete currentScene;
	currentScene = scene;
}