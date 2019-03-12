#include"Enemy.h"


Enemy::Enemy() : Task(500)                      //500フレームで消去
, m_Pos(50+Random(0,974),-15.0)
, m_Update(this, &Enemy::Update) //第2引数に指定した関数が自動で呼び出される
{  
	//受信側設定
	m_Receive.Register<Laser>(this, &Enemy::HitCheck);
}

void Enemy::Update() {

	Circle(m_Pos, 15.0).draw(Color(200, 150, 255));

	m_Pos.y+=1.5;

}

void Enemy::HitCheck(Laser & particle)
{
	

	//プレイヤーと衝突していたら消去
	if (Circle(m_Pos, 15.0).intersects(particle.getCircle())) {
		particle.SetDestroy();
		count++;
	}
	if (count == 20) {
		count = 0;
		this->Destroy();
	}
}
