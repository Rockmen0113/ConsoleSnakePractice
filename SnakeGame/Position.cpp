#include "pch.h"
#include "Position.h"

bool operator==(const Position &pos1, const Position &pos2)
{
	return (pos1.X == pos2.X
		&& pos1.Y == pos2.Y);
}

bool operator!=(const Position &pos1, const Position &pos2)
{
	return !(pos1 == pos2);
}

bool operator>(const Position & pos1, const Position & pos2)
{
	return (pos1.X > pos1.X && pos1.Y > pos1.Y);
}

bool operator>=(const Position & pos1, const Position & pos2)
{
	return (pos1.X >= pos1.X && pos1.Y >= pos1.Y);
}

bool operator<(const Position & pos1, const Position & pos2)
{
	return (pos1.X < pos1.X && pos1.Y < pos1.Y);
}

bool operator<=(const Position & pos1, const Position & pos2)
{
	return (pos1.X <= pos1.X && pos1.Y <= pos1.Y);
}
