#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>


class Laser : public Task {

private:
	Vec2        m_Pos;      //座標
	TaskCall    m_Update;   //更新設定
	TaskCall	m_Draw;
	TaskSend    m_Send; //送信設定
	void Update1();
	void Update2();
	void Update3();
	void Draw();
	const double V = 5; //Laser velocityの大きさ in vacuum
	double theta;
	const double n1 = 1.5, n2 = 1.35, n3 = 1.2; //屈折率
	int roop; //Update2内のtheta代入用roop
	int con_x,con_y; //convert用変数
	
public:
	Laser();
	void SetDestroy();
	Circle getCircle() const;
	void Convert_x();
	void Convert_y();
	
};

double Theta(Vec2 mouse);

bool Laser_create();

