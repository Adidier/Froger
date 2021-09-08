#pragma once
#include "Image.h"
#include <string>
class Obstacle
{
private:
	int PosX, PosY;
	float VelX;
	int direction;
	Image sprite;
public:
	void init(int Posx, int Posy, float Velx, int direction, std::string path);
	void move();
	void draw();
	bool reset();
};

