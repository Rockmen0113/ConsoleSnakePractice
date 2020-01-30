#include "pch.h"
#include "Input.h"

int Input::inputKey = 0;
Direction Input::oldDirection = Left;

Direction Input::getDirection()
{
	Direction direction = oldDirection;
	if (_kbhit())
	{
		inputKey = _getch();
		switch (inputKey)
		{
		case 150:
		case 230:
		case 'W':
		case 'w':
			direction = Up;
			break;
		case 155:
		case 235:
		case 'S':
		case 's':
			direction = Down;
			break;
		case 148:
		case 228:
		case 'A':
		case 'a':
			direction = Left;
			break;
		case 130:
		case 162:
		case 'D':
		case 'd':
			direction = Right;
			break;
		}

		if ((oldDirection == Up && direction == Down) || (direction == Up && oldDirection == Down)
			|| (oldDirection == Left && direction == Right) || (oldDirection == Right && direction == Left))
		{
			direction = oldDirection;
		}
	}

	oldDirection = direction;

	return direction;
}

