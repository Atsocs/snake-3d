//
// Created by atsocs on 25/04/2020.
//

#ifndef GAME_1A8FE4FF80444B289D05EF4CA4648FE7_H
#define GAME_1A8FE4FF80444B289D05EF4CA4648FE7_H

#include "Constants.h"
#include "Fruit.h"
#include "Snake.h"
#include <list>

class Game
{
public:
	Game();
	explicit Game(Snake snake);
	void draw() const;
	[[nodiscard]] bool alive() const;
	void generateRandomFruit();
	double getSnakeSpeed();
	void moveSnake();
	void turnSnakeTo(Direction direction);
	void eatFruit(std::list<Fruit>::iterator fruit);
	[[nodiscard]] int getScore() const;
private:
	int score;
	std::list<Fruit> fruits;
	Snake snake;
	[[nodiscard]] bool isPositionOccupiedWithFruit(const Position &position) const;
	[[nodiscard]] bool isPositionOccupied(const Position &position) const;
	void drawFruits() const;
	static void drawFruit(int x, int y, Color color);

	friend std::ostream &operator<<(std::ostream &os, const Game &game);
	void generateFruit(int count=1);
	void searchForFruitsToEat(const Vector &snakeHeadNext);
	void generateFruit(const Fruit &fruit);
	static void drawFruit(const Position &p);
};

std::ostream &operator<<(std::ostream &os, const Game &game);

#endif //GAME_1A8FE4FF80444B289D05EF4CA4648FE7_H
