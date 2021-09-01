#include "Image.h"

void Image::load(std::string path)
{
	SDL_Surface*dataImage = IMG_Load(path.c_str());
}

void Image::draw()
{

}
int Image::getWidth()
{
	return width;
}
int Image::getHeight()
{
	return height;
}
int Image::getPosX()
{
	return xPos;
}
int Image::getPosY()
{
	return yPos;
}