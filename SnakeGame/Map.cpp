#include "pch.h"
#include <iostream>

#include "Map.h"
#include "ConsoleSetting.h"


Position Map::getPosition() const
{
	return mapPosition;
}

int Map::getHeight() const
{
	return Height;
}

int Map::getWidth() const
{
	return Width;
}

Map::Map(Position position,int height, int width):mapPosition(position), Height(height), Width(width)
{

}

void Map::Drow()
{
	char drowSymb = ' ';

	int X = mapPosition.X;
	int Y = mapPosition.Y;

	int d_width = Width + mapPosition.X;
	int d_height = Height + mapPosition.Y;


	ConsoleSetting::GotoXY(X, Y);

	while (Y != d_height + 1)
	{
		if (X < d_width && (Y == mapPosition.Y || Y == d_height))
		{
			drowSymb = UpDownLine;
		}
		else if (Y < d_height && (X == mapPosition.X || X == d_width))
		{
			drowSymb = LeftRightLine;
		}

		if (Y == mapPosition.Y)
		{
			if (X == mapPosition.X)
			{
				drowSymb = TopLeftÑorner;
			}
			else if (X == d_width)
			{
				drowSymb = TopRightCorner;
			}
		}
		else if (Y == d_height)
		{
			if (X == mapPosition.X)
			{
				drowSymb = BotLeftCorner;
			}
			else if (X == d_width)
			{
				drowSymb = BotRightCorner;
			}
		}
		
		if (X > mapPosition.X && (Y > mapPosition.Y && Y != d_height))
		{
			ConsoleSetting::GotoXY(d_width, Y);
			X = d_width;
		}

		//Drowing
		std::cout << drowSymb;
		++X;


		if (X == d_width + 1)
		{
			X = mapPosition.X;
			++Y;
			ConsoleSetting::GotoXY(X, Y);
		}

	}

}
