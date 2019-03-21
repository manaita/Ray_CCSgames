#pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
#include<math.h>

class Battery {
private:
	Font font{ 10 };
	const double R = 75;
	double m_theta;
public:
	Battery();
	void Draw();
	double Theta(); //–C‘ä‚ÌŒü‚«
	
};