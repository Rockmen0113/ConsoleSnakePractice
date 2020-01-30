#pragma once

#include "pch.h"
#include <vector>
#include "Position.h"
#include "SnakeTail.h"
#include "ConsoleSetting.h"
#include "Fruit.h"
#include "Map.h"

class Snake
{
private:
	SnakeTail *tail;
	char Shape;
	int Size = 4;
	bool isInitialisation;

	void ArrResize(int newSize);

	void Grow();

public:
	Snake();
	Snake(int size, int X, int Y, char shape);

	SnakeTail* getTail() const;
	int getSize() const;

	void Eat(Fruit &fruit, const Map &map);
	void Move(Direction direction);

	void Drow();

	~Snake();
};