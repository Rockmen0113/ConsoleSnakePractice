#include "pch.h"
#include <iostream>
#include <thread>
//#include <gtest/gtest.h>

#include "Map.h"
#include "Snake.h"
#include "ConsoleSetting.h"
#include "Input.h"
#include "Fruit.h"

int main(int argc, char*argv[])
{
	ConsoleSetting::ShowCursor(false);
	Map map(Position(25, 5), 20, 60);
	Snake snake(4, 30, 10, '*');

	Fruit fruit('$', map.getPosition(), map.getWidth(), map.getHeight());

	while (true)
	{
		map.Drow();
		snake.Drow();

		
		snake.Move(Input::getDirection());
		snake.Eat(fruit, map);
		

		ConsoleSetting::GotoXY(0, 0);

		Sleep(200);
	}
	//testing::InitGoogleTest();
}

