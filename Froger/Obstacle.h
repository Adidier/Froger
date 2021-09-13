#pragma once
#include "Image.h"
#include <string>
class Obstacle
{
private:
	float PosX, PosY;
	float VelX;
	int direction;
	Image sprite;
public:
	void init(float Posx, float Posy, float Velx, int direction, std::string path);
	void move();
	void draw();
	bool reset();
	float getPositionX();
	void setPositionX(float PosX);
	float getWidth();
	float getHeight();
	float getPositionY();
	static bool IsCollision(float posXObj1, float posYObj1, int widthObj1, int heightObj1,
		float posXObj2, float posYObj2, int widthObj2, int heightObj2);
};

