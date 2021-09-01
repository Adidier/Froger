#pragma once
#include "SDL.h"

class Platform
{
private:
	SDL_Renderer* render;
	SDL_Window* window;
	int width;
	int height;
public:
	void init(int w, int h);
	void update()
	void draw();
	void input();
	int getWidth();
	int getHeight();
	void setWidth(int w);
	void setHeight(int h);
};

