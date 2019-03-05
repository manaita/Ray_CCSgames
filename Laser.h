#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>


class Laser : public Task {

private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;   //�X�V�ݒ�
	TaskSend    m_Send; //���M�ݒ�
	void Update();
	const double V = 5; //Laser velocity�̑傫�� in vacuum
	const double theta;
	const double n1 = 1.5, n2 = 1.35, n3 = 1.2; //���ܗ�
	
public:
	Laser();
	void SetDestroy();
	Circle getCircle() const;
	
};

double Theta(Vec2 mouse);

bool Laser_create();

