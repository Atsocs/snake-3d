//
// Created by atsocs on 25/04/2020.
//

#ifndef POSITION_574FC5C34CDD459C92BA1F462392BE14_H
#define POSITION_574FC5C34CDD459C92BA1F462392BE14_H

#include "../hardcoded/Constants.h"

#include <iostream>
#include <vector>

class Position
{
public:
	explicit Position(int dimension = DIMENSION);
	explicit Position(std::vector<int> origin);
	void setRandom();
	std::vector<int> origin;
};

bool operator==(const Position &p1, const Position &p2);
std::ostream &operator<<(std::ostream &os, const Position &position);

#endif //POSITION_574FC5C34CDD459C92BA1F462392BE14_H
