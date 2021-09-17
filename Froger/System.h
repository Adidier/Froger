#pragma once
#include "SDL.h"
#include "Image.h"
#include "Carrusel.h"
#include "Platform.h"
#include <vector>
class System
{
private:
	SDL_Renderer* render;
	SDL_Window* window;
	int width;
	int height;
	System();

	static System* ptr;
	Image imagen1;
	Image background;
	std::vector<Carrusel*> carrusels;
	std::vector<Platform*> linePlatform;
public:
	static System* getPtr();
	void init(int w, int h);
	void update();
	void UpdatePlatforms();
	void UpdateCars();
	void draw();
	void input();
	int getWidth();
	int getHeight();
	void setWidth(int w);
	void setHeight(int h);
	SDL_Renderer* getRender();
};

