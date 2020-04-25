//
// Created by atsocs on 25/04/2020.
//

#include "Fruit.h"
#include <cassert>

Fruit::Fruit(int score, int healthBenefit)
		: eaten{false}, position{}, score{score}, healthBenefit{healthBenefit}
{
	position.setRandom();
	assert(!Vector{position}.isOutOfBounds());
}

void Fruit::eat()
{
	assert(!eaten);
	eaten = true;
}
