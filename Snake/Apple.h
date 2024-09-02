#pragma once
#include <vector>

#include "Cell.h"

class Apple
{
	Coord coord;
	int fieldWidth, fieldHeight;

	bool eaten;
public: 
	Apple();
	Apple(int fieldWidth, int fieldHeight);

	void Spawn();
	void Spawn(std::vector<Coord> &snakeBody);
	bool IsApple(Coord& coord);

	void Eat();
	bool IsEaten();
};