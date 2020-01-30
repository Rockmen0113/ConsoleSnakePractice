#pragma once

#include "pch.h"
#include "Position.h"

class Map
{
private:
	enum Walls
	{
		TopLeft—orner = 201,
		TopRightCorner = 187,
		BotLeftCorner = 200,
		BotRightCorner = 188,
		UpDownLine = 205,
		LeftRightLine = 186
	};

	int Height = 80;
	int Width = 80;
	Position mapPosition;
public:
	Map(Position position, int height, int width);

	Position getPosition() const;
	int getHeight() const;
	int getWidth() const;

	void Drow();
};
