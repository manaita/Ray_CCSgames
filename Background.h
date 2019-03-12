#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include"Laser.h"

class Mirror :public Task{
private:
	TaskCall    m_Update;   //更新設定
	TaskReceive m_Receive;  //受信設定
	TaskSend    m_Send; //送信設定
	void Update();
	Rect mirror1, mirror2, mirror3, mirror4;
public:
	Mirror();
	void HitCheck(Laser &particle);
};

class Back {
private:
public:
	Back();
	void Draw();
};