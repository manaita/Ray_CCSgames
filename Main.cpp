#include "Scene.h"

void Main()
{
	SceneManager<String> manager;

	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");

	Window::Resize(1024, 640);

	//TextureAsset::Register(L"Back", L"Example/Earth.jpg");

	FontAsset::Register(L"memo", 20);

	while (System::Update())
	{
		//manager.setFadeColor(Color(255, 255, 255));
		manager.updateAndDraw();
	}
}