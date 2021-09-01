#include "Platform.h"

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
}

void Platform:: update()
{

}

void Platform::draw()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
	SDL_RenderClear(render);


	SDL_RenderPresent(render);
}

void Platform::input()
{

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