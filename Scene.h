#pragma once
#include "Battery.h"
#include"Enemy.h"
#include"Background.h"


class Title : public SceneManager<String>::Scene
{
private:
	Rect command[4];
	void m_DrawRay(double x, double y) const;
	void m_RayUpdate(double x, double y);
	Vec2 m_ray1,m_ray2;
	bool roop;
	int counter;
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{50};
};

class Game : public SceneManager<String>::Scene
{
private:
	Battery *battery;
	int time;
	int roop_count;
	Back *back;
	int m_energy_remains;
	bool m_energy_check;
	void Energy_update();
	void Energy_draw() const;
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};


class Result : public SceneManager<String>::Scene
{
private:
	Back *back;
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};

class Ranking : public SceneManager<String>::Scene
{
private:
	int h_score[6];
	FILE *file;
	void File_write();
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};


class Tips : public SceneManager<String>::Scene
{
private:
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};