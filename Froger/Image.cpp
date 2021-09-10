#include "Image.h"
#include "Platform.h"

void Image::load(std::string path)
{
	SDL_Surface* dataImage = IMG_Load(path.c_str());
	if(dataImage == nullptr)
	{
		throw "No hay imagen";
	}
	auto render = Platform::getPtr()->getRender();
	texture= SDL_CreateTextureFromSurface(render, dataImage);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
	SDL_free(dataImage);
}

void Image::draw()
{
	SDL_Rect dst;
	dst.x = xPos;
	dst.y = yPos;
	dst.w = width;
	dst.h = height;
	auto render = Platform::getPtr()->getRender();
	SDL_RenderCopy(render, texture, NULL, &dst);
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

void Image::setPosX(float x){
	xPos = x;
}
void Image::setPosY(float y){
	yPos = y;
}