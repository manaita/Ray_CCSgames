#pragma once
# include <Siv3D.hpp>
# include <rnfs.h>
#include <math.h>


class Laser : public Task {

private:
	Vec2        m_Pos;      //���W
	TaskCall    m_Update;   //�X�V�ݒ�
	TaskCall	m_Draw;
	TaskSend    m_Send; //���M�ݒ�
	void Update1();
	void Update2();
	void Update3();
	void Draw();
	const double V = 5; //Laser velocity�̑傫�� in vacuum
	double theta;
	const double n1 = 1.5, n2 = 1.35, n3 = 1.2; //���ܗ�
	int roop; //Update2����theta����proop
	int con_x,con_y; //convert�p�ϐ�
	
public:
	Laser();
	void SetDestroy();
	Circle getCircle() const;
	void Convert_x();
	void Convert_y();
	
};

double Theta(Vec2 mouse);

bool Laser_create();

