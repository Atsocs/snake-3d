//
// Created by atsocs on 25/04/2020.
//

#include "Constants.h"
#include "Snake.h"
#include <cassert>
#include <iostream>

Snake::Snake(int size, double speed)
		: alive{true}, size{size}, speed{speed}, head{}, tail{}, turns{}
{
	resetHeadTail();
}

Snake::Snake(double speed) : Snake(SNAKE_INITIAL_SIZE, speed)
{

}

void Snake::resetHeadTail()
{
	tail.centralize();
	tail.origin[0] = 1;
	head = tail + (size - 1);
}

void Snake::draw() const
{
	drawCell(head.origin[0], head.origin[1]);
	for (const auto &turn : turns)
	{
		drawCell(turn.origin[0], turn.origin[1], PINK);
	}
	drawCell(tail.origin[0], tail.origin[1], BLUE);
}

void Snake::drawCell(int x, int y)
{
	drawCell(x, y, SNAKE_COLOR);
}

void Snake::drawCell(int x, int y, Color color)
{
	DrawRectangle(BORDER_IN_PIXELS + CELL_PADDING_WIDTH_IN_PIXELS + x * CELL_WIDTH_IN_PIXELS,
	              BORDER_IN_PIXELS + CELL_PADDING_HEIGHT_IN_PIXELS + y * CELL_HEIGHT_IN_PIXELS,
	              CELL_WIDTH_IN_PIXELS - CELL_PADDING_WIDTH_IN_PIXELS * 2,
	              CELL_HEIGHT_IN_PIXELS - CELL_PADDING_HEIGHT_IN_PIXELS * 2,
	              color);
}

double Snake::getSpeed() const
{
	return speed;
}

void Snake::turnTo(Direction direction)
{
	if (!alive) return;
	assert(direction / 2 != head.direction / 2);
	head.direction = direction;
	move();
}

void Snake::move()
{
	if (!alive) return;
	if (willCollide())
	{
		alive = false;
#ifdef SNAKKE_DEBUG
		std::cout << "Snake::move(): " << "snake died for it was about to collide" << std::endl;
#endif
		return;
	}
	// now we know snake is alive and can move safely
	incrementHeadTailTurns(head, tail, turns);
}

void incrementHeadTailTurns(Vector &myHead, Vector &myTail, std::deque<Vector> &myTurns)
{
	++myHead;
	++myTail;
	if (myTail.inSamePlaceAs(myTurns.front()))
	{
		myTail.direction = myTurns.front().direction;
		myTurns.pop_front();
	}
}

bool Snake::willCollide() const
{
	auto myHead = head;
	auto myTail = tail;
	auto myTurns = turns;
	incrementHeadTailTurns(myHead, myTail, myTurns);
	return isCollidingState(myHead, myTail, myTurns);
}

bool Snake::isCollidingState(const Vector &myHead, const Vector &myTail, const std::deque<Vector> &myTurns)
{
	if (myHead.isOutOfBounds()) return true;
	Vector checkingFor = myTail;
	Vector checkUntil = (myTurns.empty() ? myHead : myTurns.front());
	int index{0};

	auto checkLine = [&]()
	{
		while (!checkingFor.inSamePlaceAs(checkUntil))
		{
			if (myHead.inSamePlaceAs(checkingFor)) return true;
			++checkingFor;
		}
		return false;
	};

	while (index < static_cast<int>(myTurns.size()))
	{
		if (checkLine()) return true;
		checkingFor.direction = checkUntil.direction;
		++index;
		checkUntil = myTurns[index];
	}
	checkUntil = myHead;
	return checkLine();

}



