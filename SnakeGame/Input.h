#pragma once

#include "Direction.h"
#include "pch.h"
#include "conio.h"

static class Input
{
private:
	static int inputKey;
	static Direction oldDirection;
public:
	static Direction getDirection();
};