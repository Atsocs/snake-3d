//
// Created by atsocs on 25/04/2020.
//

#include "Constants.h"
#include "Snake.h"
#include <cassert>
#include <iostream>

Snake::Snake(int size, double speed)
		: alive{true}, health{HEALTH_MAX}, size{size}, speed{speed}, head{}, tail{}, turns{}, mouth{},
		  stomach{}
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

void Snake::turnTo(Direction direction, bool checkForCollision)
{
	if (!alive)
	{ return; }
	assert(direction / 2 != head.direction / 2);
	head.direction = direction;
	if (size > 1)
	{ turns.push_back(head); }
	else
	{ tail.direction = direction; }
	if (checkForCollision && willCollide())
	{
		if (size > 1)
		{ turns.pop_back(); }
		alive = false;
#ifdef SNAKKE_DEBUG
		std::cout << "Snake::turnTo(): " << "snake died for it was about to collide" << std::endl;
#endif
		return;

	}
	move(false);

}

void Snake::move(bool checkForCollision)
{
#ifdef SNAKKE_DEBUG
//	std::cout << "mouth: " << mouth.size() << " stomach: " << stomach.size() << std::endl;
#endif
	if (!alive)
	{ return; }
	else if (checkForCollision && willCollide())
	{
		alive = false;
#ifdef SNAKKE_DEBUG
		std::cout << "Snake::move(): " << "snake died for it was about to collide" << std::endl;
#endif
		return;
	}
	else
	{
		// now we know snake is alive and can move safely
		incrementHeadTailTurns(head, tail, turns, mouth.empty());
		if (!mouth.empty())
		{
			++size;
			stomach.push_back(mouth.front());
			mouth.pop_front();
		}
	}
}

void incrementHeadTailTurns(Vector &myHead, Vector &myTail, std::deque<Vector> &myTurns, bool isTailSupposedToMove)
{
	++myHead;
	if (isTailSupposedToMove)
	{
		++myTail;
		if (!myTurns.empty() && myTail.inSamePlaceAs(myTurns.front()))
		{
			myTail.direction = myTurns.front().direction;
			myTurns.pop_front();
		}
	}
}

bool Snake::willCollide() const
{
	Vector myHead = head;
	Vector myTail = tail;
	std::deque<Vector> myTurns = turns;
	incrementHeadTailTurns(myHead, myTail, myTurns, mouth.empty());
	return isCollidingState(myHead, myTail, myTurns);
}

bool
Snake::isCollidingState(const Vector &myHead, const Vector &myTail, const std::deque<Vector> &myTurns)
{
	if (myHead.isOutOfBounds())
	{ return true; }

	Vector checkingFor = myTail;
	Vector checkUntil = (myTurns.empty() ? myHead : myTurns.front());
	int index{0};

	auto checkLine = [&]()
	{
		while (!checkingFor.inSamePlaceAs(checkUntil))
		{
			if (myHead.inSamePlaceAs(checkingFor))
			{
				return true;
			}
			else
			{
				++checkingFor;
			}
		}
		checkingFor.direction = checkUntil.direction;
		return false;
	};
	while (index < static_cast<int>(myTurns.size()))
	{
		if (checkLine()) return true;
		++index;
		checkUntil = (index < myTurns.size() ? myTurns[index] : myHead);
	}
	bool ret = checkLine();
	return ret;
}

void Snake::eatFruit(Fruit &fruit)
{
	fruit.eat();
	mouth.push_back(fruit);

	health += fruit.hp;
	if (health > HEALTH_MAX)
	{ health = HEALTH_MAX; }
	if (health <= 0)
	{
		health = 0;
//		die();
	}
}

bool Snake::isPositionOccupied(const Position &p) const
{
	const Vector toTest{p}; //todo: correct this ugly solution
	const auto &myTail = tail;
	const auto &myTurns = turns;
	const auto &myHead = head;
	Vector checkingFor = myTail;
	Vector checkUntil = (myTurns.empty() ? myHead : myTurns.front());
	int index{0};

	auto checkLine = [&]()
	{
		while (!checkingFor.inSamePlaceAs(checkUntil))
		{
			if (toTest.inSamePlaceAs(checkingFor)) //todo: correct this ugly solution
			{
				return true;
			}
			else
			{
				++checkingFor;
			}
		}
		checkingFor.direction = checkUntil.direction;
		return false;
	};
	while (index < static_cast<int>(myTurns.size()))
	{
		if (checkLine()) return true;
		++index;
		checkUntil = (index < myTurns.size() ? myTurns[index] : myHead);
	}
	return checkLine();
}

std::ostream &operator<<(std::ostream &os, const Snake &snake)
{
//	assert(snake.mouth.empty());
	static constexpr int identationCount = 1;
	auto identation = std::string(identationCount, '\t');
	using std::endl;
	os << "Snake: " << (snake.alive ? "alive" : "dead") << ", health " << snake.health << ", size " << snake.size
	   << ", speed " << snake.speed << endl;
	os << identation << "head: " << snake.head << ", tail: " << snake.tail << endl;
	os << identation << "turns" << (snake.turns.empty() ? " is empty." : ": ") << endl;
	for (const auto &turn : snake.turns)
	{
		os << identation << '\t' << turn << endl;
	}
	os << identation << "mouth" << (snake.mouth.empty() ? " is empty." : ": ") << endl;
	for (const auto &fruit : snake.mouth)
	{
		os << identation << '\t' << fruit << endl;
	}
	os << identation << "stomach" << (snake.stomach.empty() ? " is empty." : ": ") << endl;
	for (const auto &fruit : snake.stomach)
	{
		os << identation << '\t' << fruit << endl;
	}
	return os;
}

bool Snake::isAlive() const
{
	return alive;
}

Vector Snake::getHead() const
{
	return head;
}


