#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>
#include"Laser.h"


void HpDraw();
void ScoreDraw();
void GrobalInit();
int GetScore();

class Enemy : public Task {

private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;   //�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	TaskSend    m_Send; //���M�ݒ� HP�ɑ���
	void Update();
	void Draw();
	int count; //laser�̓���������
public:
	Enemy();
	void HitCheck(Laser & particle);
	void SetDestoy();
	Vec2 GetPos() {
		return m_Pos;
	}
};

class Stop : public Task {
private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;	//�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	TaskSend    m_Send; //���M�ݒ� HP�ɑ���
	void Update();
	void Draw();
	int count; //laser�̓���������
	double time;
	const double V = 5.0;
	const double HIGH = 130.0/V;
	const double WIDE = 442.0 / V;
	const double STOP = 300.0 / V;
	
public:
	Stop();
	void HitCheck(Laser & particle);
	void SetDestoy();
	Vec2 GetPos() {
		return m_Pos;
	}
};

class Double : public Task {
private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;	//�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	TaskSend    m_Send; //���M�ݒ� HP�ɑ���
	void Update();
	void Draw();
	int count; //laser�̓���������
	bool m_roop;
public:
	Double();
	void HitCheck(Laser & particle);
	void SetDestoy();
	Vec2 GetPos() {
		return m_Pos;
	}
};

class Heavy : public Task {
private:
	Vec2        m_Pos;      //���W
	double		m_Initx;
	TaskCall    m_Update;	//�X�V�ݒ�
	TaskCall	m_Draw;
	TaskReceive m_Receive;  //��M�ݒ�
	TaskSend    m_Send; //���M�ݒ� HP�ɑ���
	void Update();
	void Draw();
	int count; //laser�̓���������

public:
	Heavy();
	void HitCheck(Laser & particle);
	void SetDestoy();
	Vec2 GetPos() {
		return m_Pos;
	}
};
