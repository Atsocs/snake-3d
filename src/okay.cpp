//
// Created by atsocs on 25/04/2020.
//

#include "Constants.h"
#include "Game.h"
#include "okay.h"
#include "string"

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
	while (number)
	{
		number /= 10;
		digits++;
	}
	return digits;
}

void DrawEverything(const Game &game)
{
	ClearBackground(RAYWHITE);

	DrawText("Snakke", GetScreenWidth() / 2 - 185, GetScreenHeight() / 2 - 50, 100, LIGHTGRAY);

	game.draw();

	DrawText(("Score: " + std::to_string(game.getScore())).c_str(), BORDER_IN_PIXELS * 2, BORDER_IN_PIXELS * 2, 20, BLACK);
	DrawText(("Hi-Score: " + std::to_string(BISSECTRA_HI_SCORE)).c_str(), BORDER_IN_PIXELS * 2, BORDER_IN_PIXELS * 4, 20, BLACK);


	DrawBorder();
}