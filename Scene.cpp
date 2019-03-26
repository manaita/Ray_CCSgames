# include "Scene.h"

void Title::init() {
	GrobalInit();
	command[0] = Rect(70, 350, 350, 120);
	command[1] = Rect(560, 350, 350, 120);
	command[2] = Rect(130, 490, 350, 120);
	command[3] = Rect(620, 490, 350, 120);

	m_ray1.x = 0;
	m_ray1.y = 0;
	m_ray2.x = 0;
	m_ray2.y = 0;

	roop = true;

	counter = 0;
}

void Title::update()
{
	/*if (Input::MouseL.clicked) {

		changeScene(L"Game");
	}*/

	if (command[0].mouseOver) {
		m_RayUpdate(70,470);
	}
	else if (command[1].mouseOver) {
		m_RayUpdate(560, 470);
	}
	else if (command[2].mouseOver) {
		m_RayUpdate(130, 610);
	}
	else if (command[3].mouseOver) {
		m_RayUpdate(620, 610);
	}
	else {
		roop = true;
	}

}

void Title::draw() const
{
	TextureAsset(L"title_back").draw();
	TextureAsset(L"play").draw(70,350);
	TextureAsset(L"tips").draw(560,350);
	TextureAsset(L"ranking").draw(130,490);
	TextureAsset(L"exit").draw(620,490);

	if (command[0].mouseOver) {
		m_DrawRay(70, 470);
	}
	else if (command[1].mouseOver) {
		m_DrawRay(560, 470);
	}
	else if (command[2].mouseOver) {
		m_DrawRay(130, 610);
	}
	else if (command[3].mouseOver) {
		m_DrawRay(620, 610);
	}
}

void Title::m_RayUpdate(double x,double y) {
	if (roop) {
		m_ray1.x = x;
		m_ray1.y = y;
		m_ray2.x = x;
		m_ray2.y = y;
		counter = 0;
		roop = false;
	}

	if (m_ray1.x <= x + 350) {
		m_ray1.x += 5;
	}

	if (counter >= 60) {
		m_ray2.x += 5;
	}
	if (m_ray2.x >= x + 350) {
		m_ray1.x = x;
		m_ray2.x = x;
		counter = 0;
	}

	counter++;

}

void Title::m_DrawRay(double x,double y) const {
	Line(m_ray1, m_ray2).draw(5, Color(178, 192, 9));
	/*Circle(x, y, 10).draw(Color(0,0,0));
	Circle(x + 350, y, 10).draw(Color(0,0,0));
	*/
	Triangle(Vec2(x, y), Vec2(x - 20, y - 10), Vec2(x - 20, y + 10)).draw(Color(0, 0, 0));
	Triangle(Vec2(x+350, y), Vec2(x+350 + 20, y - 10), Vec2(x+350 + 20, y + 10)).draw(Color(0, 0, 0));
	Triangle(Vec2(x, y), Vec2(x - 20, y - 10), Vec2(x - 20, y + 10)).drawFrame(0,3,Color(178, 192, 9));
	Triangle(Vec2(x+350, y), Vec2(x+350 + 20, y - 10), Vec2(x+350 + 20, y + 10)).drawFrame(0,3,Color(178, 192, 9));

}

//------------------------------------------

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
	if (GetHp() <= 0) {
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
	Energy_draw();
	
	
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

void Game::Energy_draw() const
{
	FontAsset(L"memo")(m_energy_remains).draw(700, 0);
	Rect(700, 50, 300, 25).draw(Color(255, 0, 0));
	Rect(700 + m_energy_remains * 3, 50, (100 - m_energy_remains) * 3, 25).draw();

}

//----------------------------------------------

void Result::init() {
	
}

void Result::update()
{
	if (Input::MouseL.clicked) {

		changeScene(L"Ranking");
	}
}

void Result::draw() const
{
	back->Draw();

	Rect(200, 100, 624, 440).draw(Color(0, 100, 255, 200));

	FontAsset(L"memo")(L"Result").draw(100, 50, Color(0, 0, 0));
	FontAsset(L"memo")(GetScore()).draw(400, 400, Color(0, 0, 0));
}

//----------------------------------------------

void Ranking::init()
{
	fopen_s(&file, "result.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf_s(file, "%d", h_score + i);
	}
	fclose(file);

	File_write();
}

void Ranking::update()
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

void Ranking::draw() const
{
	Window::ClientRect().draw(Palette::Blue);
	font(L"Ranking").drawCenter(Window::Center());

	FontAsset(L"memo")(GetScore()).draw();
	for (int i = 0; i < 5; i++) {
		FontAsset(L"memo")(h_score[i]).draw(0, 100+50 * i);
	}
}

void Ranking::File_write() {
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
