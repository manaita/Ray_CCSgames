#include "Laser.h"

const double X0 = 512;
const double Y0 = 640;

Vec2 init_mouse;

Laser::Laser() : Task()                      //60ƒtƒŒ[ƒ€‚ÅÁ‹Ž
, m_Pos(X0, Y0)
, m_Update(this, &Laser::Update) //‘æ2ˆø”‚ÉŽw’è‚µ‚½ŠÖ”‚ªŽ©“®‚ÅŒÄ‚Ño‚³‚ê‚é
, theta(Theta(init_mouse))
{
	//‘—M‘¤“o˜^
	m_Send.Register(this);
}

void Laser::Update() {

	double n;//‹üÜ—¦
	double the;//Šp“x

	if (m_Pos.y > 480) {
		n = n1;
		the = theta;
	}
	else if (m_Pos.y <= 480 && 390 < m_Pos.y) {
		n = n2;
		the = 90_deg - asin((n1 / n2)*cos(theta));
	}
	else if (m_Pos.y <= 390 && 320 < m_Pos.y) {
		n = n3;
		the = 90_deg - asin((n2 / n3)*sin(asin((n1 / n2)*cos(theta))));
	}
	else {
		n = 1;
		the= 90_deg - asin((n3)*sin(asin((n2 / n3)*sin(asin((n1 / n2)*cos(theta))))));
	}




	m_Pos.x += (V / n) * cos(the);
	m_Pos.y -= (V / n) * sin(the);

	//•`‰æ
	Circle(m_Pos, 4.0).draw(Color(0, 150, 255));
	//Circle(m_Pos, 3.0).draw(Color(0, 150, 255, 200));

}

void Laser::SetDestroy()
{
	//Á‹Ž
	this->Destroy();
}

Circle Laser::getCircle() const
{
	//•`‰æ‚·‚é‰~‚ð•Ô‚·
	return Circle(m_Pos, 4.0);
}

//-----------------------------------------------

double Theta(Vec2 mouse) {

	double theta;

	theta = 360_deg-atan2(mouse.y - Y0, mouse.x - X0);

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

