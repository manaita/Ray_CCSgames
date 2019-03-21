# include "Scene.h"

void Title::init() {
	GrobalInit();
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
	roop_count = 0;
	Create<Mirror>();
	m_energy_remains = 100;
	m_energy_check = true;
	}

void Game::update()
{
	if (Input::MouseR.clicked) {
		Task::All::Clear();
		changeScene(L"Result");
	}

	time++;
	if (time == 300) {
		roop_count++;
		time = 0;
	}

	Energy_update();
}

void Game::draw() const
{
	back->Draw();

	
	if (Laser_create() && m_energy_check) {
		Create<Laser>();
	}

	Mirror_Draw();
	
	if (time == 200) {
		Create<Enemy>();
		
	}
	if (roop_count > 15 && time == 150) {
		Create<Enemy>;
	}

	if (roop_count > 30) {
		if (roop_count % 2 == 0 && time == 250) {
			Create<Stop>();
		}
	}
	if (roop_count > 60) {
		if (time == 100) {
			Create<Double>();
		}
	}
	if (roop_count > 90) {
		if (time == 50) {
			Create<Heavy>();
		}
	}
	
	
	battery->Draw();
	HpDraw();
	ScoreDraw();

	FontAsset(L"memo")(m_energy_remains).draw(700, 0);

	//TaskSend と TaskReceive で設定した関数を呼び出す
	TaskSend::All::Update();

	//TaskCall で設定した関数を呼び出す
	TaskCall::All::Update();
	//Destroy を呼び出したタスクを消去
	Task::All::Update();

}

void Game::Energy_update() {
	if (Input::MouseL.pressed) {
		m_energy_remains--;
		if (m_energy_remains <= 0) {
			m_energy_check = false;
			m_energy_remains = 0;
		}
	}
	else {
		m_energy_check = true;
		if (m_energy_remains < 100) {
			m_energy_remains += 3;
		}
		else {
			m_energy_remains = 100;
		}
	}
}

//----------------------------------------------


void Result::init()
{
	fopen_s(&file, "result.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf_s(file, "%d", h_score + i);
	}
	fclose(file);

	File_write();
}

void Result::update()
{
	if (Input::MouseL.clicked) {
		fopen_s(&file, "result.txt", "r");
		for (int i = 0; i < 5; i++) {
			fscanf_s(file, "%d", h_score + i);
		}
		fclose(file);
		changeScene(L"Title");
	}
}

void Result::draw() const
{
	Window::ClientRect().draw(Palette::Blue);
	font(L"Result").drawCenter(Window::Center());

	FontAsset(L"memo")(GetScore()).draw();
	for (int i = 0; i < 5; i++) {
		FontAsset(L"memo")(h_score[i]).draw(0, 100+50 * i);
	}
}

void Result::File_write() {
	h_score[5] = GetScore();

	int temp;

	for (int i = 5; i > 0; i--) {
		if (h_score[i - 1] < h_score[i]) {
			temp = h_score[i];
			h_score[i] = h_score[i - 1];
			h_score[i - 1] = temp;

		}
	}

	fopen_s(&file, "result.txt", "w");
	for (int i = 0; i < 5; i++) {
		fprintf(file, "%d\n", h_score[i]);
	}
	fclose(file);
}
