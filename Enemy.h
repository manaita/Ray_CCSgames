#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>
#include"Laser.h"


class Enemy : public Task {

private:
	Vec2        m_Pos;      //座標
	TaskCall    m_Update;   //更新設定
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //受信設定
	void Update();
	void Draw();
	int count; //laserの当たった数
public:
	Enemy();
	void HitCheck(Laser & particle);
};

class Stop : public Task {
private:
	Vec2        m_Pos;      //座標
	TaskCall    m_Update;	//更新設定
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //受信設定
	void Update();
	void Draw();
	int count; //laserの当たった数
	double time;
	const double V = 5.0;
	const double HIGH = 100.0/V;
	const double WIDE = 442.0 / V;
	const double STOP = 200.0 / V;
	
public:
	Stop();
	void HitCheck(Laser & particle);
};

class Double : public Task {
private:
	Vec2        m_Pos;      //座標
	TaskCall    m_Update;	//更新設定
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //受信設定
	void Update();
	void Draw();
	int count; //laserの当たった数
	double time;
	const double V = 5.0;
	const double HIGH = 100.0 / V;
	const double WIDE = 442.0 / V;
	const double STOP = 200.0 / V;

public:
	Double();
	void HitCheck(Laser & particle);
};
