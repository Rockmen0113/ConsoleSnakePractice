#ifndef SNAKETAIL_H
#define SNAKETAIL_H

#include "pch.h"
#include "Position.h"
#include "Direction.h"

class SnakeTail
{
public:
	Position position;
	Direction direction;

	SnakeTail();

	SnakeTail(Direction direction, Position position);
};

#endif