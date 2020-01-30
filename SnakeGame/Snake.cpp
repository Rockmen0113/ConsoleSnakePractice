#include <iostream>
#include "pch.h"

//#include "Direction.h"
#include "Snake.h"
//#include "ConsoleSetting.h"

Snake::Snake()
{
	Shape = '*';
	++Size;
	tail = new SnakeTail[Size];
	isInitialisation = true;

	for (int i = 0; i < Size; i++)
	{
		tail[i] = SnakeTail(Left, Position(0 + i, 0));
	}
}

Snake::Snake(int size, int X, int Y, char shape)
{
	if (size > 0)
	{
		Shape = shape;
		Size = size + 1;
		tail = new SnakeTail[Size];
		isInitialisation = true;

		for (int i = 0; i < Size; i++)
		{
			tail[i] = SnakeTail(Left, Position(X + i, Y));
		}
	}
	else
	{
		throw "Incorrect snake size";
	}
}

SnakeTail* Snake::getTail() const
{
	return tail;
}

int Snake::getSize() const
{
	return Size;
}

void Snake::Eat(Fruit &fruit, const Map &map)
{
	if ((tail[0].position == fruit.getPosition()) || isInitialisation)								// Eating Fruit
	{
		isInitialisation = false;
		Grow();
		Position tmp;

		bool isRepeating;
		do
		{
			isRepeating = false;
			tmp = fruit.generatePositionRange(map.getPosition(), map.getWidth(), map.getHeight());
			for (int i = 0; i < Size; i++)
			{
				if (tmp == tail[i].position)
				{
					isRepeating = true;
				}
			}

		} while (isRepeating);

		fruit.Draw();
	}


	for (int i = 1; i < Size; i++)												// Snake Death
	{
		if (tail[0].position == tail[i].position)
		{
			ConsoleSetting::GotoXY(50, 10);
			std::cout << "Game Over";
			Sleep(2000);
			ConsoleSetting::GotoXY(0, 30);
			exit(0);
		}
	}


	if (tail[0].position.X == map.getPosition().X)								// Snake teleportation
	{
		tail[0].position.X = map.getPosition().X + map.getWidth() - 1;
	}
	else if (tail[0].position.X == map.getPosition().X + map.getWidth())
	{
		tail[0].position.X = map.getPosition().X + 1;
	}

	if (tail[0].position.Y == map.getPosition().Y)
	{
		tail[0].position.Y = map.getPosition().Y + map.getHeight() - 1;
	}
	else if (tail[0].position.Y == map.getPosition().Y + map.getHeight())
	{
		tail[0].position.Y = map.getPosition().Y + 1;
	}
}

void Snake::Drow()
{
	for (int i = 0; i < Size; i++)
	{
		ConsoleSetting::GotoXY(tail[i].position.X, tail[i].position.Y);
		std::cout << Shape;
	}

	ConsoleSetting::GotoXY(tail[Size - 1].position.X, tail[Size - 1].position.Y); //remove tail
	std::cout << ' ';
}

void Snake::Move(Direction direction)
{
	for (int i = Size - 1; i > 0; i--)
	{
		tail[i].direction = tail[i - 1].direction;
		tail[i].position = tail[i - 1].position;
	}

	tail[0].direction = direction;

	switch (tail[0].direction)
	{
	case Up:
		--tail[0].position.Y;
		break;
	case Down:
		++tail[0].position.Y;
		break;
	case Left:
		--tail[0].position.X;
		break;
	case Right:
		++tail[0].position.X;
		break;
	}

	//if (tail[i].direction == Up)
	//{
	//	--tail[i].position.Y;
	//}
	//else if (tail[i].direction == Down)
	//{
	//	++tail[i].position.Y;
	//}
	//else if (tail[i].direction == Left)
	//{
	//	--tail[i].position.X;
	//}
	//else if (tail[i].direction == Right)
	//{
	//	++tail[i].position.X;
	//}

}

void Snake::ArrResize(int newSize)
{
	SnakeTail *tmp = new SnakeTail[newSize];
	for (int i = 0; i < Size; i++)
	{
		tmp[i] = tail[i];
	}
	Size = newSize;
	delete[] tail;
	tail = tmp;
}

void Snake::Grow()
{
	ArrResize(Size + 1);
	tail[Size - 1].direction = tail[Size - 2].direction;
	tail[Size - 1].position = tail[Size - 2].position;

	switch (tail[Size - 2].direction)
	{
	case Up:
		tail[Size - 1].position.Y = tail[Size - 2].position.Y - 1;
		break;
	case Down:
		tail[Size - 1].position.Y = tail[Size - 2].position.Y + 1;
		break;
	case Left:
		tail[Size - 1].position.X = tail[Size - 2].position.X + 1;
		break;
	case Right:
		tail[Size - 1].position.X = tail[Size - 2].position.X - 1;
		break;
	}
}

Snake::~Snake()
{
	delete[] tail;
	tail = nullptr;
}