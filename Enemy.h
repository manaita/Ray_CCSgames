#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>
#include"Laser.h"


class Enemy : public Task {

private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;   //�X�V�ݒ�
	TaskReceive m_Receive;  //��M�ݒ�
	void Update();
	int count; //laser�̓���������
public:
	Enemy();
	void HitCheck(Laser & particle);
};
