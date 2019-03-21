#include"Enemy.h"


int g_hp = 100;
int g_score = 0;

void HpDraw() {
	FontAsset(L"memo")(g_hp).draw();
}

void ScoreDraw() {
	FontAsset(L"memo")(g_score).draw(100, 0);
}

void GrobalInit() {
	g_hp = 100;
	g_score = 0;
}

int GetScore() {
	return g_score;
}

//--------------------------------------------------

Enemy::Enemy() : Task(900)                      //500フレームで消去
, m_Pos(50+Random(0,974),-15.0)
, m_Update(this, &Enemy::Update) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Enemy::Draw)
, count(0)
{  
	//受信側設定
	m_Receive.Register<Laser>(this, &Enemy::HitCheck);
	//送信側設定
	m_Send.Register(this);

}

void Enemy::Update() {

	if (m_Pos.y <= 320) {
		m_Pos.y += 1.5;
	}
	else if (m_Pos.y <= 390) {
		m_Pos.y += 1.3;
	}
	else if (m_Pos.y <= 480) {
		m_Pos.y += 1.0;
	}
	else {
		m_Pos.y += 0.8;
	}
	if (m_Pos.y >= 530) {
		g_hp -= 3;
		this->Destroy();
	}
	
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
		g_score += 3;
		this->Destroy();
	}

	
}

void Enemy::SetDestoy() {
	this->Destroy();
}

//---------------------------------------------------------------------

Stop::Stop() : Task(5000)                      //500フレームで消去
, m_Pos(70, -10.0)
, m_Update(this, &Stop::Update) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Stop::Draw)
, time(-12)
, count(0)
{
	//受信側設定
	m_Receive.Register<Laser>(this, &Stop::HitCheck);
	//送信側設定
	m_Send.Register(this);

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

	if (m_Pos.y >= 530) {
		g_hp -= 5;
		this->Destroy();
	}
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
		g_score += 5;
		this->Destroy();
	}
}


void Stop::SetDestoy() {
	this->Destroy();
}

//-------------------------------------------------------------------


Double::Double() : Task(900)                      //500フレームで消去
, m_Pos(100 + Random(0, 824), -15.0)
, m_Update(this, &Double::Update) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Double::Draw)
, count(0)
{
	//受信側設定
	m_Receive.Register<Laser>(this, &Double::HitCheck);
	//送信側設定
	m_Send.Register(this);

}

void Double::Update() {

	if (m_Pos.y <= 320) {
		m_Pos.y += 1.5;
	}
	else if (m_Pos.y <= 390) {
		m_Pos.y += 1.3;
	}
	else if (m_Pos.y <= 480) {
		m_Pos.y += 1.0;
	}
	else {
		m_Pos.y += 0.8;
	}
	if (m_Pos.y >= 530) {
		g_hp -= 7;
		this->Destroy();
	}
}

void Double::Draw() {

	if (count <= 20) {
		Circle(m_Pos, 20.0).drawFrame(0, 5, Color(255, 100, 100));
	
	}
	Circle(m_Pos, 10.0).draw(Color(255, 100, 100));

}

void Double::HitCheck(Laser & particle)
{

	//プレイヤーと衝突していたら消去
	if (count <= 20) {
		if (Circle(m_Pos, 20.0).intersects(particle.getCircle())) {
			particle.SetDestroy();
			count++;
		}
	}
	else {
		if (Circle(m_Pos, 10.0).intersects(particle.getCircle())) {
			particle.SetDestroy();
			count++;
		}
	}
	if (count == 40) {
		count = 0;
		g_score += 7;
		this->Destroy();
	}
}


void Double::SetDestoy() {
	this->Destroy();
}

//----------------------------------------------------------

Heavy::Heavy() : Task(900)                      //500フレームで消去
, m_Pos(200+Random(0,624), -15.0)
, m_Update(this, &Heavy::Update) //第2引数に指定した関数が自動で呼び出される
, m_Draw(this, &Heavy::Draw)
, m_Initx(m_Pos.x)
, count(0)
{
	//受信側設定
	m_Receive.Register<Laser>(this, &Heavy::HitCheck);
	//送信側設定
	m_Send.Register(this);

}

void Heavy::Update() {

	if (m_Pos.y <= 320) {
		m_Pos.y += 1.3;
	}
	else if (m_Pos.y <= 390) {
		m_Pos.y += 1.1;
	}
	else if (m_Pos.y <= 480) {
		m_Pos.y += 0.8;
	}
	else {
		m_Pos.y += 0.6;
	}

	m_Pos.x = 100 * sin(m_Pos.y / 50.0) + m_Initx;

	if (m_Pos.y >= 530) {
		g_hp -= 10;
		
		this->Destroy();
	}

}

void Heavy::Draw() {

	Circle(m_Pos, 20.0).draw(Color(100, 255, 100));

}

void Heavy::HitCheck(Laser & particle)
{

	//プレイヤーと衝突していたら消去
	
	if (Circle(m_Pos, 20.0).intersects(particle.getCircle())) {
		particle.SetDestroy();
		count++;
	}
	if (count == 60) {
		count = 0;
		g_score += 10;
		this->Destroy();
	}
}


void Heavy::SetDestoy() {
	this->Destroy();
}