#pragma once
#include <vector>
#include <string>
#include "Obstacle.h"

using namespace std;
class Carrusel
{
private:
	vector<Obstacle> obstacles;
	int posY;
	int direction;
	string path;
public:
	void init(string path, int Posy, int dir);
	void draw();
	void update();
};

