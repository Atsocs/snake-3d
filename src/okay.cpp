//
// Created by atsocs on 25/04/2020.
//

#include "Constants.h"
#include "okay.h"

void DrawBorder()
{
	DrawRectangle(0, 0, GetScreenWidth(), BORDER_IN_PIXELS, BORDER_COLOR);
	DrawRectangle(0, GetScreenHeight() - BORDER_IN_PIXELS, GetScreenWidth(), BORDER_IN_PIXELS, BORDER_COLOR);
	DrawRectangle(0, BORDER_IN_PIXELS, BORDER_IN_PIXELS, GetScreenHeight() - BORDER_IN_PIXELS * 2, BORDER_COLOR);
	DrawRectangle(GetScreenWidth() - BORDER_IN_PIXELS, BORDER_IN_PIXELS, BORDER_IN_PIXELS,
	              GetScreenHeight() - BORDER_IN_PIXELS * 2, BORDER_COLOR);
}

bool isSpecialFrame(int frames, double speed)
{
	if (speed == 0.0)
	{ return false; }
	const int mod = static_cast<int>(TARGET_FPS / speed);
	return frames % mod == (mod - 1);
}

int numDigits(int number)
{
	int digits = 0;
	if (number < 0) digits = 1; // remove this line if '-' counts as a digit
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}