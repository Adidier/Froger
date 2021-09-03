#pragma once
#include "SDL_image.h"
#include <string>
class Image
{
private:
	int width;
	int height;
	int xPos, yPos;
	SDL_Texture* texture;
public:
	void load(std::string path);
	void draw();
	int getWidth();
	int getHeight();
	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);
};
