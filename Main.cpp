#include "Scene.h"

void Load() {
	TextureAsset::Register(L"title_back", L"Data/title_back.png");
	TextureAsset::Register(L"play", L"Data/play.png");
	TextureAsset::Register(L"tips", L"Data/tips.png");
	TextureAsset::Register(L"ranking", L"Data/rank.png");
	TextureAsset::Register(L"exit", L"Data/exit.png");
	
	
	TextureAsset::Register(L"Back", L"Data/background.png");
	TextureAsset::Register(L"enemy", L"Data/enemy.jpg");

	FontAsset::Register(L"memo", 20);
}

void Main()
{
	SceneManager<String> manager;

	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");
	manager.add<Ranking>(L"Ranking");


	Window::Resize(1024, 640);

	Load();

	while (System::Update())
	{
		//manager.setFadeColor(Color(255, 255, 255));
		manager.updateAndDraw();
	}
}

