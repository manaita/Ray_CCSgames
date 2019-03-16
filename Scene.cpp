# include "Scene.h"

void Title::init() {
}

void Title::update()
{
	if (Input::MouseL.clicked) {

		changeScene(L"Game");
	}
}

void Title::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	font(L"Title").drawCenter(Window::Center());

}


void Game::init()
	{
	battery = new Battery;
	time = 0;
	Create<Mirror>();
	}

void Game::update()
{
	/*if (Input::MouseL.clicked) {
		Task::All::Clear();
		changeScene(L"Result");
	}*/

	time++;
	if (time == 200) {
		time = 0;
	}
}

void Game::draw() const
{
	back->Draw();

	if (Laser_create()) {
		Create<Laser>();
	}

	Mirror_Draw();
	
	if (time == 199) {
		//Create<Enemy>();
		Create<Stop>();
	}
	
	
	
	battery->Draw();

	//TaskSend と TaskReceive で設定した関数を呼び出す
	TaskSend::All::Update();

	//TaskCall で設定した関数を呼び出す
	TaskCall::All::Update();
	//Destroy を呼び出したタスクを消去
	Task::All::Update();

}



void Result::init()
{

}

void Result::update()
{
	if (Input::MouseL.clicked) {
		changeScene(L"Title");
	}
}

void Result::draw() const
{
	Window::ClientRect().draw(Palette::Blue);
	font(L"Result").drawCenter(Window::Center());
}
