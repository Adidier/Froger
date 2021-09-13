#pragma once
#include <vector>
#include <string>
#include "Obstacle.h"

using namespace std;
class Carrusel
{
private:
	vector<Obstacle*> obstacles;
	int posY;  
	int number;
	int direction;
	int widthScreen;
	string path;
public:
	void init(int number, int numObstacles,string path, int Posy, int dir, float vel, int dist, int width);
	void draw();
	void update();
	vector<Obstacle*> *GetObstacles();
};

