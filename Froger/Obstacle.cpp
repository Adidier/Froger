#include "Obstacle.h"

void Obstacle::init(int Posx, int Posy, float Velx, int direction, std::string path)
{
	PosX = Posx;
	PosY = Posy;
	VelX = Velx;
	this->direction = direction;
	sprite.load(path);
	sprite.setPosX(PosX);
	sprite.setPosY(PosY);
}

void Obstacle::move()
{
	if (direction >= 1)
		PosX += VelX;
	else if (direction <= -1)
		PosX -= VelX;
	sprite.setPosX(PosX);
}

void Obstacle::draw()
{
	sprite.draw();
}

bool Obstacle::reset()
{
	return false;
}