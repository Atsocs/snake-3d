//
// Created by atsocs on 25/04/2020.
//

#include "MovesQueue.h"
#include <cassert>
#include <iostream>

MovesQueue::MovesQueue()
		: lastPushed{static_cast<Direction>(0)}, q{}
{

}

bool MovesQueue::empty()
{
	return q.empty();
}

void MovesQueue::add(Direction dir)
{
#ifdef DEBUG_ALL
	static int added{0};
	std::cout << "MovesQueue::add(Direction dir):" << "move #" << ++added << std::endl;
#endif
	if (lastPushed / 2 == dir / 2)
		return;
	lastPushed = dir;
	q.push(dir);
}

int MovesQueue::size()
{
	return static_cast<int>(q.size());
}

Direction MovesQueue::front()
{
	return q.front();
}

void MovesQueue::pop()
{
	assert(!empty());
	q.pop();
}

void handleMoveKeys(MovesQueue &q)
{
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) q.add(DIR_RIGHT);
	else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) q.add(DIR_LEFT);
	else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) q.add(DIR_DOWN);
	else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) q.add(DIR_UP);
}