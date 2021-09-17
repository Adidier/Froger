#include "Obstacle.h"

void Obstacle::init(float Posx, float Posy, float Velx, int direction, std::string path)
{
	PosX = Posx;
	PosY = Posy;
	VelX = Velx;
	this->direction = direction;
	sprite.load(path);
	sprite.setPosX(PosX);
	sprite.setPosY(PosY);
}

float Obstacle::move()
{
	float dir=0;
	if (direction >= 1)
		dir += VelX;
	else if (direction <= -1)
		dir -= VelX;
	PosX = PosX + dir;
	sprite.setPosX(PosX);
	return dir;
}

void Obstacle::draw()
{
	sprite.draw();
}

bool Obstacle::reset()
{
	return false;
}

float Obstacle::getWidth()
{
	return sprite.getWidth();
}

float Obstacle::getPositionX()
{
	return PosX;
}


float Obstacle::getHeight()
{
	return sprite.getHeight();
}

float Obstacle::getPositionY()
{
	return PosY;
}

void Obstacle::setPositionX(float PosX)
{
	this->PosX = PosX;
}

bool Obstacle::IsCollision(float posXObj1, float posYObj1, int widthObj1, int heightObj1,
	float posXObj2, float posYObj2, int widthObj2, int heightObj2)
{
	if (posXObj1 < posXObj2 + widthObj2 &&
		posXObj1 + widthObj1 > posXObj2 &&
		posYObj1 < posYObj2 + heightObj2 &&
		posYObj1 + heightObj1 > posYObj2) //derecha
	{
		return true;
	}
	else if (posXObj1 < posXObj2 + widthObj2 &&
		posXObj1 + widthObj1 > posXObj2 + widthObj2 &&
		posYObj1 < posYObj2 + heightObj2 &&
		posYObj1 + heightObj1 > posYObj2)//izq
	{
		return true;
	}

	if (posYObj1 < posYObj2 + heightObj2 &&
		posYObj1 + heightObj1 > posYObj2 + heightObj2 &&
		posXObj1 < posXObj2 + widthObj2 &&
		posXObj1 + widthObj1 > posXObj2 + widthObj2) //arriba 
	{
		return true;
	}
	else if (posYObj1 + heightObj1 > posYObj2 &&
		posYObj1 < posYObj2 + heightObj2 &&
		posXObj1 < posXObj2 + widthObj2 &&
		posXObj1 + widthObj1 > posXObj2 + widthObj2) //debajo 
	{
		return true;
	}
	return false;
}