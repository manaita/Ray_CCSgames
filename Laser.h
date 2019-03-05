#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>


class Laser : public Task {

private:
	Vec2        m_Pos;      //座標
	TaskCall    m_Update;   //更新設定
	TaskSend    m_Send; //送信設定
	void Update();
	const double V = 5; //Laser velocityの大きさ in vacuum
	const double theta;
	const double n1 = 1.5, n2 = 1.35, n3 = 1.2; //屈折率
	
public:
	Laser();
	void SetDestroy();
	Circle getCircle() const;
	
};

double Theta(Vec2 mouse);

bool Laser_create();

