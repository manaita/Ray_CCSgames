#include "Laser.h"

const double X0 = 512;
const double Y0 = 640;

Vec2 init_mouse;

Laser::Laser() : Task()                      //60フレームで消去
, m_Pos(X0, Y0)
, m_Update(this, &Laser::Update1) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Laser::Draw)
, theta(Theta(init_mouse))
, roop(0)
, con_x(1)
, con_y(1)
{
	//送信側登録
	m_Send.Register(this);
	
}

void Laser::Update1() {

	double n=1;//屈折率
	double the=0;//角度

	if (m_Pos.y > 480) {
		n = n1;
		the = theta;
	}
	else if (m_Pos.y <= 480 && 390 < m_Pos.y) {
		n = n2;
		the = asin((n1 / n2)*sin(theta));
	}
	else if (m_Pos.y <= 390 && 320 <= m_Pos.y) {
		n = n3;
		the = asin((n1 / n3)*sin(theta));
	}
	else {
		n = 1;
		theta = asin(n1*sin(theta));
		m_Pos.x -= (V / n) * sin(the);
		m_Pos.y += (V / n) * cos(the);
		m_Update.SetCall(&Laser::Update2);
	}


	m_Pos.x += (V /n) * sin(the);
	m_Pos.y -= (V/n) * cos(the);

	
	if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>660) {
		this->Destroy();
	}

}

void Laser::Update2() {

	
	m_Pos.x += con_x * V * sin(theta);
	m_Pos.y -= con_y * V * cos(theta);

	if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>660) {
		this->Destroy();
	}

	if (m_Pos.y > 320) {
		
		theta = atan((con_x * V * sin(theta)) / (-con_y * V * cos(theta)));
		m_Update.SetCall(&Laser::Update3);
	}
}

void Laser::Convert_x() {
	con_x *= -1;
}

void Laser::Convert_y() {
	con_y *= -1;
}

void Laser::Update3() {

	double n=1;//屈折率
	double the=0;//角度

	if (m_Pos.y > 480) {
		n = n1;
		the = asin((1 / n1)*sin(theta));
	}
	else if (m_Pos.y <= 480 && 390 < m_Pos.y) {
		n = n2;
		the = asin((1 / n2)*sin(theta));
	}
	else if (m_Pos.y <= 390 && 320 <= m_Pos.y) {
		n = n3;
		the = asin((1 / n3)*sin(theta));
	}
	else {
		n = 1;
		//the = theta;
	}

	
	m_Pos.x += (V /n ) * sin(the);
	m_Pos.y += (V /n) * cos(the);


	if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>530) {
		this->Destroy();
	}
}

void Laser::Draw() {
	//描画
	Circle(m_Pos, 4.0).draw(Color(0, 150, 255));
	//Circle(m_Pos, 3.0).draw(Color(0, 150, 255, 200));
}

void Laser::SetDestroy()
{
	//消去
	this->Destroy();
}

Circle Laser::getCircle() const
{
	//描画する円を返す
	return Circle(m_Pos, 4.0);
}

//-----------------------------------------------

double Theta(Vec2 mouse) {

	double theta;

	theta = atan((mouse.x - X0) / (-mouse.y + Y0));

	return theta;
}

bool Laser_create() {

	if (Input::MouseL.clicked) {
		init_mouse.x = Mouse::Pos().x;
		init_mouse.y = Mouse::Pos().y;
		
	}
	if (Input::MouseL.pressed) {
		return true;
	}

	return false;
}

