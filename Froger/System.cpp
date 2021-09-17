#include "System.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

System* System::ptr = nullptr;

System::System()
{

}

System* System::getPtr()
{
	if (ptr == nullptr)
	{
		ptr = new System();
	}
	return ptr;
}

SDL_Renderer* System::getRender()
{
	return render;
}

void System::init(int w, int h)
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

	background.load("assets/background.png");
	background.setPosX(0);
	background.setPosY(0);

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

	for (int i = 0; i < 3; ++i)
	{
		Platform* obst = new Platform();
		obst->init(i * (obst->getWidth() + 30), 170, 2, 1, "assets/log.png");
		linePlatform.push_back(obst);
	}


}

void System:: update()
{
	UpdateCars();
	UpdatePlatforms();
}

void System::UpdatePlatforms()
{
	for (auto obs : linePlatform)
	{
		float dir = obs->move();
		if (Obstacle::IsCollision(imagen1.getPosX(), imagen1.getPosY(), imagen1.getWidth(), imagen1.getHeight(),
			obs->getPositionX(), obs->getPositionY(), obs->getWidth(), obs->getHeight()))
		{
			imagen1.setPosX(imagen1.getPosX() + dir);
		}
	}
}

void System::UpdateCars()
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

void System::draw()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
	SDL_RenderClear(render);

	background.draw();

	for (auto log : linePlatform)
	{
		log->draw();
	}	

	imagen1.draw();
	for (auto car : carrusels)
	{
		car->draw();
	}	


	SDL_RenderPresent(render);
}

void System::input()
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

int System::getWidth()
{
	return width;
}

int System::getHeight()
{
	return height;
}

void System::setWidth(int w)
{
	width = w;
}

void System::setHeight(int h)
{
	height = h;
}