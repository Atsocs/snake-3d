//
// Created by atsocs on 25/04/2020.
//

#include "Vector.h"
#include <cassert>

Vector::Vector(int dimension)
		: origin(dimension), direction{static_cast<Direction>(0)}
{
	assert(origin.size() == dimension);
}

void Vector::centralize()
{
	for (auto &coordinate : origin)
	{
		coordinate = BOARD_SIZE / 2;
	}
}
