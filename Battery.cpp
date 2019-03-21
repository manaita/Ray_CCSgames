#include "Battery.h"

const double X0 = 512;
const double Y0 = 640;


Battery::Battery():
	m_theta(0)
{

}

void Battery::Draw() {
	Circle(X0, Y0, 60).draw(Color(100, 100, 100, 180));
	Line(X0, Y0, X0 + R * cos(Theta()), Y0 + R * sin(Theta())).drawArrow(3, { 15, 15 }, Color(70, 70, 70, 180));
	//font(Mouse::Pos()).draw();
}

double Battery::Theta() {

	if (Input::MouseL.pressed == false) {
		double mousex = Mouse::Pos().x;
		double mousey = Mouse::Pos().y;

		m_theta = atan2(mousey - Y0, mousex - X0);
	}

	return m_theta;
}
