#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include"Laser.h"

class Mirror :public Task{
private:
	TaskCall    m_Update;   //�X�V�ݒ�
	TaskReceive m_Receive;  //��M�ݒ�
	TaskSend    m_Send; //���M�ݒ�
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