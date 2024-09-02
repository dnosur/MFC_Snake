#pragma once
#include "vector"
#include "Cell.h"
#include "Apple.h"

#define LEFT_DIRECTION 0
#define RIGHT_DIRECTION 1
#define UP_DIRECTION 2
#define DOWN_DIRECTION 3

class Field;

class SnakeController
{
	Coord head;
	Coord tail;
	std::vector<Coord> body;

	int direction;
	int fieldHeight, fieldWidth;

	void MoveHead();
public: 
	SnakeController();
	SnakeController(int fieldHeight, int fieldWidth);

	Coord& GetHead();

	int GetSize();

	int GetDirection();
	void SetDirection(int direction);

	void Move();
	void Eat(Apple& apple);

	bool IsSnake(Coord& coord);
	bool IsDie();

	std::vector<Coord> GetBody();
};