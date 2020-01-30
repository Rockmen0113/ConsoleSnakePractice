#pragma once

#include <iostream>
#include <cstdlib>
#include <random>
#include "Position.h"
#include "ConsoleSetting.h"

class Fruit
{
private:
	Position position;
	char Shape;	
	bool isCanDraw;

	int randomValue(int start, int range);
public:
	Fruit();
	Fruit(char shape, Position position, int width, int height);

	Position getPosition() const;
	
	Position generatePositionRange(const Position startPosition,const int width,const int height);

	void Draw();
	//void Draw(Position startPosition, int width, int height, const Snake &snake);
};