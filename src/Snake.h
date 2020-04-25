//
// Created by atsocs on 25/04/2020.
//

#ifndef SNAKE_E8F14F9C6AAF4C8C9A63581A42E82530_H
#define SNAKE_E8F14F9C6AAF4C8C9A63581A42E82530_H


#include <deque>
#include "Vector.h"

class Snake
{
public:
	explicit Snake(int size = SNAKE_INITIAL_SIZE, double speed = SNAKE_INITIAL_SPEED);
	explicit Snake(double speed);
	void draw() const;
	void move(bool checkForCollision = true);
	void turnTo(Direction direction, bool checkForCollision = true);
	[[nodiscard]] double getSpeed() const;
private:
	[[nodiscard]] bool willCollide() const;
	[[nodiscard]] static bool
	isCollidingState(const Vector &myHead, const Vector &myTail, const std::deque<Vector> &myTurns);
	void resetHeadTail();
	static void drawCell(int x, int y);
	static void drawCell(int x, int y, Color color);
	bool alive;
	int size;
	double speed;
	Vector head;
	Vector tail;
	std::deque<Vector> turns;
};

void incrementHeadTailTurns(Vector &myHead, Vector &myTail, std::deque<Vector> &myTurns);

#endif //SNAKE_E8F14F9C6AAF4C8C9A63581A42E82530_H
