#include "Carrusel.h"

void Carrusel::init(int number, int numObstacles, string path, int Posy, int dir, float vel, int dist, int width)
{
	this->number = number;
	direction = dir;
	widthScreen = width;
	for (int i = 0; i < numObstacles; ++i)
	{
		Obstacle* obst = new Obstacle();
		obst->init(i *( obst->getWidth() + dist), Posy, vel, dir, path);
		obstacles.push_back(obst);
	}
}

void Carrusel::draw()
{
	for(int i = 0; i < obstacles.size(); ++i)
	{
		obstacles[i]->draw();
	}
}

void Carrusel::update()
{
	for(int i = 0; i < obstacles.size(); ++i)
	{
		obstacles[i]->move();
		if(obstacles[i]->getPositionX()< -obstacles[i]->getWidth() && direction < 0)
		{
			obstacles[i]->setPositionX(widthScreen);//width screen
		}
		else if(obstacles[i]->getPositionX()> widthScreen && direction > 0)
		{
			obstacles[i]->setPositionX(obstacles[i]->getWidth() * -1);
		}
	}
}

vector<Obstacle*>* Carrusel::GetObstacles()
{
	return &obstacles;
}