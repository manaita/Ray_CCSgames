#pragma once
#include "Battery.h"
#include"Laser.h"
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
	Battery* battery;
	int time;
	Back *back;
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};

class Result : public SceneManager<String>::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;
	Font font{ 50 };
};
