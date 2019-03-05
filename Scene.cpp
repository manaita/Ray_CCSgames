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
	}

void Game::update()
{
	/*if (Input::MouseL.clicked) {
		Task::All::Clear();
		changeScene(L"Result");
	}*/

	time++;
	if (time == 100) {
		time = 0;
	}
}

void Game::draw() const
{
	Window::ClientRect().draw(Color(20, 20, 50));
	Rect(0, 320, 1024, 320).draw(Color(30, 30, 200, 80));
	Rect(0, 390, 1024, 250).draw(Color(50, 50, 200, 80));
	Rect(0, 480, 1024, 160).draw(Color(70, 70, 250, 80));

	if (Laser_create()) {
		Create<Laser>();
	}
	
	if (time == 99) {
		Create<Enemy>();
	}
	
	Rect(0, 630, 1024, 10).draw(Color(170, 170, 170, 180));
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
