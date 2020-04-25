//
// Created by atsocs on 25/04/2020.
//

#ifndef VECTOR_C14AC72190144CEC9580B7AF89EABAD3_H
#define VECTOR_C14AC72190144CEC9580B7AF89EABAD3_H

#include "Constants.h"
#include "Direction.h"
#include <vector>

class Vector
{
public:
	explicit Vector(int dimension=DIMENSION);
	void centralize();
private:
	std::vector<int> origin;
	Direction direction;
};


#endif //VECTOR_C14AC72190144CEC9580B7AF89EABAD3_H
