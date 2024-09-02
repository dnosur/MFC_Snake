#include "pch.h"
#include "Field.h"

void Field::ResetField(Cell** field)
{

	if (!GetWidth() || !GetHeight()) {
		return;
	}

	this->field = new Cell*[GetHeight()];

	for (int i = 0; i < GetHeight(); i++) {
		this->field[i] = new Cell[GetWidth()];
		for (int j = 0; j < GetWidth(); j++) {
			this->field[i][j] = field == nullptr
				? Cell()
				: field[i][j];
		}
	}

	apple = Apple(width, height);
}

void Field::SpawnSnake()
{
	snake = SnakeController(height, width);
}

Field::Field()
{
	left = right = top = bottom = 10;
	width = height = 10;
	//ResetField();
}

Field::Field(const int X, const int Y, int width, int height): 
	width(width), height(height), 
	left(X), right(X),
	top(Y), bottom(Y)
{
	ResetField();
}

Field::Field(const int left, const int right, const int top, const int bottom, int width, int height) :
	left(left), right(right), top(top), bottom(bottom), width(width), height(height)
{
	ResetField();
}

Field::Field(const Field& other)
	: left(other.left), right(other.right), top(other.top), bottom(other.bottom), 
	width(other.width), height(other.height), snake(other.snake), apple(other.apple)
{
	ResetField(other.field);
}

Field& Field::operator=(const Field& other)
{
	if (this == &other) {
		return *this; // самоприсваивание
	}

	left = other.left;
	right = other.right;
	top = other.top;
	bottom = other.bottom;

	width = other.width;
	height = other.height;

	ResetField(other.field);

	return *this;
}

Field::~Field()
{
	if (field != nullptr) {
		delete[] field;
	}
}

void Field::Draw(CPaintDC& pDC, CRect& clientRect)
{
	if (snake.IsDie()) {
		return;
	}

	pDC.SetBkColor(RGB(255, 255, 255));
	pDC.SetBkMode(OPAQUE);

	bool isNeedSpawn = snake.GetHead().X <= -1 || snake.GetHead().Y <= -1;

	if (!isNeedSpawn) {
		snake.Move();
	}

	for (int i = 0; i < GetHeight(); ++i) {
		for (int j = 0; j < GetWidth(); ++j) {
			if (field[i][j].coord.X >= 0 && field[i][j].coord.Y >= 0) {
				bool isSnake = snake.IsSnake(field[i][j].coord);
				bool isApple = apple.IsApple(field[i][j].coord);

				if (isApple && isSnake) {
					snake.Eat(apple);
				}

				pDC.Rectangle(&field[i][j].rect);
				pDC.FillSolidRect(field[i][j].rect, isSnake ? SNAKE_COLOR : isApple ? APPLE_COLOR : FIELD_COLOR);
				continue;
			}

			
			CRect cellRect(left + clientRect.left + j * cellSize + padding, top + clientRect.top + i * cellSize + padding,
				right + clientRect.left + (j + 1) * cellSize + padding, bottom + clientRect.top + (i + 1) * cellSize + padding);
			pDC.Rectangle(&cellRect);
			pDC.FillSolidRect(cellRect, FIELD_COLOR);
			field[i][j] = Cell(Coord(j, i), cellRect);
		}
	}

	if (isNeedSpawn) {
		SpawnSnake();
	}

	if (apple.IsEaten()) {
		apple.Spawn(snake.GetBody());
	}
}

void Field::Update(CPaintDC& pDC)
{
	pDC.FillSolidRect(field[0][1].rect, SNAKE_COLOR);
}

const int Field::GetWidth()
{
	return width;
}

const int Field::GetHeight()
{
	return height;
}

Cell& Field::operator[](const Coord& coord)
{
	if (field == nullptr) {
		throw "Field is empty!";
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (field[i][j].coord == coord) {
				return field[i][j];
			}
		}
	}
	throw "Cell is't exist!";
}

SnakeController& Field::GetSnake()
{
	return snake;
}
