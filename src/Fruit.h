//
// Created by atsocs on 25/04/2020.
//

#ifndef FRUIT_2963903581E544B6AABAEFD1E24314F4_H
#define FRUIT_2963903581E544B6AABAEFD1E24314F4_H

#include "Constants.h"
#include "Vector.h"
#include "Position.h"

class Fruit
{
public:
	explicit Fruit(int score = FRUIT_BASE_SCORE, int healthBenefit = FRUIT_BASE_HEALTH_BENEFIT);
	void eat();
	bool eaten;
	Position position;
	int score;
	int hp;
	friend std::ostream & operator<< (std::ostream & os, const Fruit & fruit);
};

std::ostream & operator<< (std::ostream & os, const Fruit & fruit);

#endif //FRUIT_2963903581E544B6AABAEFD1E24314F4_H
