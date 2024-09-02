#pragma once
#include "Cell.h"
#include "Apple.h"
#include "SnakeController.h"
#include "ColorRefs.h"

class SnakeController;

class Field
{
	Cell** field;

	Apple apple;
	SnakeController snake;

	int left, right, top, bottom;
	int width, height;

	const int fieldSize = 300;
	const int cellSize = fieldSize / 10;

	const int padding = 10;

	void ResetField(Cell** field = nullptr);

	void SpawnSnake();
public:
	Field();
	Field(const int X, const int Y, int width = 10, int height = 10);
	Field(const int left, const int right, const int top, const int bottom, 
		int width = 10, int height = 10
	);

	Field(const Field& other);
	Field& operator=(const Field& other);

	~Field();

	void Draw(CPaintDC& pDC, CRect& clientRect);
	void Update(CPaintDC& pDC);

	const int GetWidth();
	const int GetHeight();

	SnakeController& GetSnake();

	Cell& operator[](const Coord& coord);
};

