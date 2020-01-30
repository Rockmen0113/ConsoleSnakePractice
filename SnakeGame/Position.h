#pragma once

#include "pch.h"
#include <iostream>

class Position
{
public:
	int X;
	int Y;

	Position()
	{
		X = 0;
		Y = 0;
	}

	Position(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
	}

	friend bool operator== (const Position &pos1, const Position &pos2);
	friend bool operator!= (const Position &pos1, const Position &pos2);

	friend bool operator> (const Position &pos1, const Position &pos2);
	friend bool operator>= (const Position &pos1, const Position &pos2);

	friend bool operator< (const Position &pos1, const Position &pos2);
	friend bool operator<= (const Position &pos1, const Position &pos2);
};