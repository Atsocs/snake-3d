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
	void draw();
	void generateFruit();
	double getSnakeSpeed();
	void moveSnake();
	void turnSnakeTo(Direction direction);
	void eatFruit(std::list<Fruit>::iterator fruit);
private:
	int score;
	std::list<Fruit> fruits;
	Snake snake;
	[[nodiscard]] bool isPositionOccupiedWithFruit(const Position &position) const;
	[[nodiscard]] bool isPositionOccupied(const Position &position) const;
	void drawFruits();
	static void drawFruit(int x, int y);
};


#endif //GAME_1A8FE4FF80444B289D05EF4CA4648FE7_H
