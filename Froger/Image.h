#pragma once
#include "SDL_image.h"
#include <string>
class Image
{
private:
	int width;
	int height;
	float xPos, yPos;
	SDL_Texture* image;
public:
	void load(std::string path);
	void draw();
	int getWidth();
	int getHeight();
	int getPosX();
	int getPosY();
};
