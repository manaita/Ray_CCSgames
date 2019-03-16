#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>
#include"Laser.h"


class Enemy : public Task {

private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;   //�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	void Update();
	void Draw();
	int count; //laser�̓���������
public:
	Enemy();
	void HitCheck(Laser & particle);
};

class Stop : public Task {
private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;	//�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	void Update();
	void Draw();
	int count; //laser�̓���������
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
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;	//�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	void Update();
	void Draw();
	int count; //laser�̓���������
	double time;
	const double V = 5.0;
	const double HIGH = 100.0 / V;
	const double WIDE = 442.0 / V;
	const double STOP = 200.0 / V;

public:
	Double();
	void HitCheck(Laser & particle);
};
