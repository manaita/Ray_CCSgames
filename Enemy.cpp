#include"Enemy.h"


Enemy::Enemy() : Task()                      //60�t���[���ŏ���
, m_Pos(0,50+Random(-20,250))
, m_Update(this, &Enemy::Update) //��2�����Ɏw�肵���֐��������ŌĂяo�����
{  
	//��M���ݒ�
	m_Receive.Register<Laser>(this, &Enemy::HitCheck);
}

void Enemy::Update() {

	Circle(m_Pos, 15.0).draw(Color(200, 150, 255));

	m_Pos.x+=1.5;

}

void Enemy::HitCheck(Laser & particle)
{
	//�v���C���[�ƏՓ˂��Ă��������
	if (Circle(m_Pos, 15.0).intersects(particle.getCircle())) {
		particle.SetDestroy();
		count++;
	}
	if (count == 20) {
		count = 0;
		this->Destroy();
	}
}
