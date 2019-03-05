#include "Scene.h"

void Main()
{
	SceneManager<String> manager;

	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");

	Window::Resize(1024, 640);

	while (System::Update())
	{
		//manager.setFadeColor(Color(255, 255, 255));
		manager.updateAndDraw();
	}
}