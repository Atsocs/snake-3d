//
// Created by atsocs on 25/04/2020.
//

#include "okay.h"
#include "Vector.h"
#include <iomanip>
#include <cassert>

Vector::Vector(int dimension)
		: origin(dimension), direction{static_cast<Direction>(0)}
{
	assert(origin.size() == dimension);
}

Vector::Vector(const Position &p)
		: origin{p.origin}, direction{static_cast<Direction>(0)}
{

}

void Vector::centralize()
{
	for (auto &coordinate : origin)
	{
		coordinate = BOARD_SIZE / 2;
	}
}

Vector &Vector::operator+=(int value)
{
	if (isPositiveDirection(direction))
	{
		origin[direction / 2] += value;
	}
	else
	{
		origin[direction / 2] -= value;
	}
	return *this;
}

Vector &Vector::operator-=(int value)
{
	return (*this += (-value));
}

Vector &Vector::operator++()
{
	return (*this += 1);
}

Vector &Vector::operator--()
{
	return (*this += (-1));
}


Vector operator+(const Vector &v, int value)
{
	Vector ret = v;
	ret += value;
	return ret;
}

Vector operator+(int value, const Vector &v)
{
	return v + value;
}

bool Vector::inSamePlaceAs(const Vector &v) const
{
	return origin == v.origin;
}

bool Vector::isOutOfBounds() const
{
	for (auto coordinate : origin)
	{
		if (coordinate < 0 || coordinate >= BOARD_SIZE) return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
	static const std::vector<std::string_view> directions{"RIGHT", "LEFT", "DOWN", "UP", "BELOW", "ABOVE"};
	assert(directions.size() == MAX_DIRECTION);

	static const int digits = numDigits(BOARD_SIZE - 1);
	os << '[';
	for (int index{0}; index < vector.origin.size(); ++index)
	{
		os << std::setw(digits) << vector.origin[index] << ' ';
	}
	os << directions[vector.direction] << ']';
	return os;
}