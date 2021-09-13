#include "Platform.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Platform* Platform::ptr = nullptr;

Platform::Platform()
{

}

Platform* Platform::getPtr()
{
	if (ptr == nullptr)
	{
		ptr = new Platform();
	}
	return ptr;
}

SDL_Renderer* Platform::getRender()
{
	return render;
}

void Platform::init(int w, int h)
{
	setWidth(w);
	setHeight(h);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw "Error al inicializar  l aventana";
	}
	else
	{
		window = SDL_CreateWindow("Froger", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			throw "Error al crear una ventana";
		}
		else
		{ 
			render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (render == nullptr)
			{
				throw "Error";
			}
			else
			{
				SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
			}
		}
	}



	imagen1.load("assets/frog.png");
	imagen1.setPosX(w/2 - imagen1.getWidth());
	imagen1.setPosY(h- imagen1.getHeight());
	srand(time(NULL));

	for(int i = 1; i < 4; i++)
	{
		Carrusel* car = new Carrusel();
		if (rand() % 100 > 50)
		{
			car->init(i, i * 5, "assets/car.png", h - 60 * i, -1, 2, 200, w);
		}
		else
		{
			car->init(i, i * 5, "assets/car.png", h - 60 * i, 1, 2, 200, w);
		}
		carrusels.push_back(car);
	}
}

void Platform:: update()
{
	for (auto car : carrusels)
	{
		car->update();
		for (auto obs : *car->GetObstacles())
		{
			if (Obstacle::IsCollision(imagen1.getPosX(), imagen1.getPosY(), imagen1.getWidth(), imagen1.getHeight(),
				obs->getPositionX(), obs->getPositionY(), obs->getWidth(), obs->getHeight()))
			{
				std::cout << "Muerto";
			}
		}
	}
}

void Platform::draw()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
	SDL_RenderClear(render);

	imagen1.draw();
	for (auto car : carrusels)
	{
		car->draw();
	}	
	SDL_RenderPresent(render);
}

void Platform::input()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
	}
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

	if (keyboard[SDL_SCANCODE_W])
	{
		if (imagen1.getPosY() - 10 > 0) {
			imagen1.setPosY(imagen1.getPosY() - 10);
		}
	}
	else if (keyboard[SDL_SCANCODE_S])
	{
		if (imagen1.getPosY() + 10 + imagen1.getHeight() < getHeight()) {
			imagen1.setPosY(imagen1.getPosY() + 10);
		}
	}
	if(keyboard[SDL_SCANCODE_A]){
		if (imagen1.getPosX() - 10 > 0) {
			imagen1.setPosX(imagen1.getPosX() - 10);
		}
	} 
	else if ( keyboard[SDL_SCANCODE_D])
	{
		if(imagen1.getPosX() + 10 + imagen1.getWidth() < getWidth()){
			imagen1.setPosX(imagen1.getPosX() + 10);
		}
		
	}

}


int Platform::getWidth()
{
	return width;
}
int Platform::getHeight()
{
	return height;
}
void Platform::setWidth(int w)
{
	width = w;
}
void Platform::setHeight(int h)
{
	height = h;
}