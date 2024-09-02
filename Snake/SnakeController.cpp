#include "pch.h"
#include "SnakeController.h"
#include "Field.h"

void SnakeController::MoveHead()
{
	if (direction == LEFT_DIRECTION) {
		int newX = head.X - 1;
		head = Coord(newX >= 0
			? newX
			: fieldWidth - 1, 
			head.Y
		);
	}

	if (direction == RIGHT_DIRECTION) {
		int newX = head.X + 1;
		head = Coord(newX < fieldWidth
			? newX
			: 0,
			head.Y
		);
	}

	if (direction == UP_DIRECTION) {
		int newY = head.Y - 1;
		head = Coord(head.X, newY >= 0
			? newY
			: fieldHeight - 1
		);
	}

	if (direction == DOWN_DIRECTION) {
		int newY = head.Y + 1;
		head = Coord(head.X, newY < fieldHeight
			? newY
			: 0
		);
	}
}

SnakeController::SnakeController()
{
	direction = rand() % 4;

	fieldWidth = fieldHeight = -1;
}

SnakeController::SnakeController(int fieldHeight, int fieldWidth):
	head(Coord(rand()%fieldWidth, rand()%fieldHeight)), direction(rand()%4), 
	fieldHeight(fieldHeight), fieldWidth(fieldWidth)
{
	body.push_back(head);
}

Coord& SnakeController::GetHead()
{
	return head;
}

int SnakeController::GetSize()
{
	return body.size();
}

int SnakeController::GetDirection()
{
	return direction;
}

void SnakeController::SetDirection(int direction)
{
	this->direction = direction >= 0 && direction <= 3 ? direction : this->direction;
}

void SnakeController::Move()
{
	if (fieldWidth <= 0 || fieldHeight <= 0 || !body.size()) {
		return;
	}

	tail = body.size() <= 1 ? head : body[body.size() - 1];
	MoveHead();

	if (body.size() == 1) {
		body[0] = head;
		return;
	}

	Coord prevPos = body[0];
	for (int i = 0; i < body.size(); i++) {
		Coord temp = body[i];
		body[i] = prevPos;
		prevPos = temp;
	}

	body[0] = head;
}

void SnakeController::Eat(Apple& apple)
{
	apple.Eat();
	body.push_back(tail);
}

bool SnakeController::IsSnake(Coord& coord)
{
	for (Coord& item : body) {
		if (item == coord) {
			return true;
		}
	}

	return false;
}

bool SnakeController::IsDie()
{
	for (int i = 0; i < body.size(); i++) {
		for (int j = 0; j < body.size(); j++) {
			if (i == j) {
				continue;
			}

			if (body[i] == body[j]) {
				return true;
			}
		}
	}
	return false;
}

std::vector<Coord> SnakeController::GetBody()
{
	return body;
}
