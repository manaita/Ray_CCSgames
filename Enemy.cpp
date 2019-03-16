#include"Enemy.h"


Enemy::Enemy() : Task(500)                      //500フレームで消去
, m_Pos(50+Random(0,974),-15.0)
, m_Update(this, &Enemy::Update) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Enemy::Draw)
{  
	//受信側設定
	m_Receive.Register<Laser>(this, &Enemy::HitCheck);
}

void Enemy::Update() {

	m_Pos.y+=1.5;

}

void Enemy::Draw() {

	Circle(m_Pos, 15.0).draw(Color(200, 150, 255));

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

//---------------------------------------------------------------------

Stop::Stop() : Task(5000)                      //500フレームで消去
, m_Pos(70, -10.0)
, m_Update(this, &Stop::Update) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Stop::Draw)
, time(-12)
{
	//受信側設定
	m_Receive.Register<Laser>(this, &Stop::HitCheck);
}

void Stop::Update() {

	if (time <= HIGH || ((HIGH + STOP * 3 + WIDE * 2) < time && time < (HIGH * 2 + STOP * 3 + WIDE * 2))) {
		m_Pos.y += V;
	}
	else if ((HIGH + STOP < time && time <= HIGH + STOP + WIDE) || ((HIGH + STOP * 2 + WIDE) < time && time < (HIGH + STOP * 2 + WIDE * 2))) {
		m_Pos.x += V;
	}
	else if (((HIGH * 2 + STOP * 4 + WIDE * 2) < time && time < (HIGH * 2 + STOP * 4 + WIDE * 3)) || ((HIGH * 2 + STOP * 5 + WIDE * 3) < time && time < (HIGH * 2 + STOP * 5 + WIDE * 4))) {
		m_Pos.x -= V;
	}
	else if (time >= (HIGH * 2 + STOP * 6 + WIDE * 4)) {
		time = 0;
	}

	time++;
}

void Stop::Draw() {

	Circle(m_Pos, 15.0).draw(Color(255, 150, 0));

}


void Stop::HitCheck(Laser & particle)
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

//-------------------------------------------------------------------

