#include "Laser.h"

const double X0 = 512;
const double Y0 = 640;

Vec2 init_mouse;

Laser::Laser() : Task(3600)                      //60ÉtÉåÅ[ÉÄÇ≈è¡ãé
, m_Pos(X0, Y0)
, m_Update(this, &Laser::Update1) 
, m_Draw(this, &Laser::Draw)
, theta(Theta(init_mouse))
, roop(0)
, con_x(1)
, con_y(1)
, con_y1(1)
, n(1)
, the(0)
, t_ref_check(true)
, theta_draw(0)
, v_draw(0)
{
	//ëóêMë§ê›íË
	m_Send.Register(this);
	
}

void Laser::Update1() {

	if (roop == 0) {
	
		n = n1;
		the = theta;
		roop = 1;
	}
	

	if (m_Pos.y <= 480 && m_Pos.y>390) {
		n = n2;
		the = asin((n1 / n2)*sin(theta));

		if (0_deg <= the, the < 90_deg) {
		}
		else {

			con_y1 *= -1;
			the = theta;
			t_ref_check = false;
		}
	}
	else if (m_Pos.y <= 390 && m_Pos.y>320) {

		n = n3;
		the = asin((n1 / n3)*sin(theta));
		if (0_deg <= the, the < 90_deg) {

		}
		else {
			con_y1 *= -1;
			the= asin((n1 / n2)*sin(theta));
			t_ref_check = false;
		}
	}
	else if (m_Pos.y <= 320) {
		the = asin(n1*sin(theta));
		if (0_deg <= the, the < 90_deg) {
			n = 1;
			theta = asin(n1*sin(theta));
			m_Pos.x -= (V / n) * sin(the);
			m_Pos.y += (V / n) * cos(the);
			con_y1 = 1;
			m_Update.SetCall(&Laser::Update2);
		}
		else {
		
			con_y1 *= -1;
			the= asin((n1 / n3)*sin(theta));
			t_ref_check = false;
		}
	}

	m_Pos.x += (V / n) * sin(the);
	m_Pos.y -= con_y1 * (V / n) * cos(the);

	if (t_ref_check) {
		if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>660) {
			this->Destroy();
		}
	}
	else {
		if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>530) {
			this->Destroy();
		}
	}

	theta_draw = atan((con_y1 * (V / n) * cos(the)) / ((V / n) * sin(the)));
	v_draw = V / (2.0*n);
}

void Laser::Update2() {


	m_Pos.x += con_x * V * sin(theta);
	m_Pos.y -= con_y * V * cos(theta);

	if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>660) {
		this->Destroy();
	}

	if (m_Pos.y >= 320) {
		
		theta = atan((con_x * V * sin(theta)) / (-con_y * V * cos(theta)));
		con_x = 1;
		con_y = 1;
		m_Update.SetCall(&Laser::Update3);
	}

	theta_draw = atan((con_y * V * cos(theta)) / (con_x * V * sin(theta)));
	v_draw = V/2.0;
}

void Laser::Convert_x() {
	con_x *= -1;
}

void Laser::Convert_y() {
	con_y *= -1;
}

void Laser::Update3() {


	if (m_Pos.y > 480) {
		n = n1;
		the = asin((1 / n1)*sin(theta));
		
	}
	else if (m_Pos.y <= 480 && 390 < m_Pos.y) {
		n = n2;
		the = asin((1 / n2)*sin(theta));
		
	}
	else if (m_Pos.y <= 390 && 320 < m_Pos.y) {
		n = n3;
		the = asin((1 / n3)*sin(theta));
		
	}
	else {
		n = 1;
		
	}

	m_Pos.x += (V / n) * sin(the);
	m_Pos.y += (V / n) * cos(the);

	
	if (m_Pos.x < -20 || m_Pos.x>1050 || m_Pos.y < -20 || m_Pos.y>530) {
		this->Destroy();
	}

	theta_draw = atan(((V / n) * cos(the)) / -((V / n) * sin(the)));
	v_draw = V / (2.0*n);
}

void Laser::Draw() {

	//ï`âÊ
	//Circle(m_Pos, 8.0).draw(Color(0, 150, 255, 100));

	//Line(m_Pos.x - 1.0 * cos(theta_draw), m_Pos.y + 1.0 * sin(theta_draw), m_Pos.x + 1.0 * cos(theta_draw), m_Pos.y - 1.0 * sin(theta_draw)).draw(8, Color(0, 155, 255, 100));

	//Circle(m_Pos, 8.0).draw(Color(0, 155, 255));
	if (m_Pos.y < 115 || (318 < m_Pos.y && m_Pos.y < 325) || (388 < m_Pos.y && m_Pos.y < 395) || (478 < m_Pos.y && m_Pos.y < 485) || (315 > m_Pos.y && (m_Pos.x < 25 || 999 < m_Pos.x))) {
		Circle(m_Pos, 7.5).draw(Color(0, 250, 250,50));
		Circle(m_Pos, 2.5).draw(Color(255, 255, 255));
		
	}
	else {
		Line(m_Pos.x - v_draw * cos(theta_draw), m_Pos.y + v_draw * sin(theta_draw), m_Pos.x + v_draw * cos(theta_draw), m_Pos.y - v_draw * sin(theta_draw)).draw(15, Color(0, 250, 250,50));
		Line(m_Pos.x - v_draw * cos(theta_draw), m_Pos.y + v_draw * sin(theta_draw), m_Pos.x + v_draw * cos(theta_draw), m_Pos.y - v_draw * sin(theta_draw)).draw(5, Color(255, 255, 255));
	
	}

}

void Laser::SetDestroy()
{
	this->Destroy();
}

Circle Laser::getCircle() const
{

	//ï`âÊÇ∑ÇÈâ~Çï‘Ç∑
	return Circle(m_Pos, 5.0);

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

