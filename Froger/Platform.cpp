#include "Platform.h"

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
	imagen1.setPosX(0);
	imagen1.setPosY(0);
	car.init(500, 100, 0.0001, -1, "assets/frog.png");
}

void Platform:: update()
{
	car.move();
}

void Platform::draw()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
	SDL_RenderClear(render);

	imagen1.draw();
	car.draw();

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
		if (imagen1.getPosY() - 1 > 0) {
			imagen1.setPosY(imagen1.getPosY() - 1);
		}
	}
	else if (keyboard[SDL_SCANCODE_S])
	{
		if (imagen1.getPosY() + 1 + imagen1.getHeight() < getHeight()) {
			imagen1.setPosY(imagen1.getPosY() + 1);
		}
	}
	if(keyboard[SDL_SCANCODE_A]){
		if (imagen1.getPosX() - 1 > 0) {
			imagen1.setPosX(imagen1.getPosX() - 1);
		}
	} 
	else if ( keyboard[SDL_SCANCODE_D])
	{
		if(imagen1.getPosX() + 1 + imagen1.getWidth() < getWidth()){
			imagen1.setPosX(imagen1.getPosX() + 1);
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