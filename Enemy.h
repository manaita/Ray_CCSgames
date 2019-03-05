#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>
#include"Laser.h"


class Enemy : public Task {

private:
	Vec2        m_Pos;      //座標
	TaskCall    m_Update;   //更新設定
	TaskReceive m_Receive;  //受信設定
	void Update();
	int count; //laserの当たった数
public:
	Enemy();
	void HitCheck(Laser & particle);
};
