#include "pch.h"
#include "Fruit.h"
#include <vector>


Fruit::Fruit()
{
	Shape = '$';
	generatePositionRange(Position(), 0, 0);
}

Fruit::Fruit(char shape, Position position, int width, int height)
{
	this->Shape = shape;
	generatePositionRange(position, width, height);
}

Position Fruit::getPosition() const
{
	return position;
}

Position Fruit::generatePositionRange(const Position startPosition, const int width, const int height)
{
	Position tmp;
	tmp.X = randomValue(startPosition.X + 1, startPosition.X + width - 1);       
	tmp.Y = randomValue(startPosition.Y + 1, startPosition.Y + height - 1);      

	this->position = tmp;
	return tmp;
}

int Fruit::randomValue(int start, int range)
{
	std::random_device rd;
	std::mt19937 random(rd());
	return random() % (range - start + 1) + start;
}

void Fruit::Draw()
{
	ConsoleSetting::GotoXY(position.X, position.Y);

	std::cout << Shape;
}
