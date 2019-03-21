#pragma once
#include "Battery.h"
#include"Enemy.h"
#include"Background.h"


class Title : public SceneManager<String>::Scene
{
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
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};

class Result : public SceneManager<String>::Scene
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
