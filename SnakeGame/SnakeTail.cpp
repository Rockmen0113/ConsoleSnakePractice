#include "pch.h"
#include "SnakeTail.h"

SnakeTail::SnakeTail()
{
	position.X = 0;
	position.Y = 0;
	direction = Left;
}

SnakeTail::SnakeTail(Direction direction, Position position)
{
	this->direction = direction;
	this->position = position;
}
