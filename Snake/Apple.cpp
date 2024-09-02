#include "pch.h"
#include "Apple.h"

Apple::Apple()
{
	eaten = true;
	fieldWidth = fieldHeight = 0;
}

Apple::Apple(int fieldWidth, int fieldHeight): 
	fieldWidth(fieldWidth), fieldHeight(fieldHeight), eaten(true)
{
}

void Apple::Spawn()
{
	eaten = false;
	coord = Coord(rand() % fieldWidth, rand() % fieldHeight);
}

void Apple::Spawn(std::vector<Coord>& snakeBody)
{
	while (true) {
		Spawn();

		for (Coord& snake : snakeBody) {
			if (snake == coord) {
				continue;
			}
		}

		return;
	}
}

bool Apple::IsApple(Coord& coord)
{
	return this->coord == coord;
}

void Apple::Eat()
{
	eaten = true;
}

bool Apple::IsEaten()
{
	return eaten;
}
