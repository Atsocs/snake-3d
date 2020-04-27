//
// Created by atsocs on 25/04/2020.
//

#include <cassert>
#include "Constants.h"
#include "Game.h"
#include "okay.h"
#include "string"
#include "ColorsCharlesCorrea.h"


void DrawBorder()
{
	// Game Square
	// > Horizontal
	DrawRectangle(BORDER_IN_PIXELS + LEFT_PANEL_WIDTH, 0, GAME_WIDTH + 2 * BORDER_IN_PIXELS, BORDER_IN_PIXELS,
	              BORDER_COLOR_GAME);
	DrawRectangle(BORDER_IN_PIXELS + LEFT_PANEL_WIDTH, GAME_HEIGHT + BORDER_IN_PIXELS,
	              GAME_WIDTH + 2 * BORDER_IN_PIXELS, BORDER_IN_PIXELS,
	              BORDER_COLOR_GAME);
	// > Vertical
	DrawRectangle(BORDER_IN_PIXELS + LEFT_PANEL_WIDTH, BORDER_IN_PIXELS, BORDER_IN_PIXELS, GAME_HEIGHT,
	              BORDER_COLOR_GAME);
	DrawRectangle(BORDER_IN_PIXELS + LEFT_PANEL_WIDTH + BORDER_IN_PIXELS + GAME_WIDTH, BORDER_IN_PIXELS,
	              BORDER_IN_PIXELS, GAME_HEIGHT,
	              BORDER_COLOR_GAME);
	// Left Panel
	// > Horizontal
	DrawRectangle(0, 0, LEFT_PANEL_WIDTH + 2 * BORDER_IN_PIXELS, BORDER_IN_PIXELS, BORDER_COLOR_LEFT_PANEL);
	DrawRectangle(0, LEFT_PANEL_HEIGHT + BORDER_IN_PIXELS, LEFT_PANEL_WIDTH + 2 * BORDER_IN_PIXELS, BORDER_IN_PIXELS,
	              BORDER_COLOR_LEFT_PANEL);
	// > Vertical
	DrawRectangle(0, BORDER_IN_PIXELS, BORDER_IN_PIXELS, GAME_HEIGHT, BORDER_COLOR_LEFT_PANEL);
	DrawRectangle(LEFT_PANEL_WIDTH + BORDER_IN_PIXELS, BORDER_IN_PIXELS, BORDER_IN_PIXELS, GAME_HEIGHT,
	              BORDER_COLOR_LEFT_PANEL);

}

void DrawLeftPanel()
{
//	assert(GetColor(ColorCharlesCorrea::APPLE_GREEN, 3).size() >= BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		DrawCell(0, i, GetCharlesColor(i), 0);
	}
}

void DrawCell(int x, int y, Color color, int leftPadding)
{
	DrawRectangle(leftPadding + BORDER_IN_PIXELS + CELL_PADDING_WIDTH_IN_PIXELS + x * CELL_WIDTH_IN_PIXELS,
	              BORDER_IN_PIXELS + CELL_PADDING_HEIGHT_IN_PIXELS + y * CELL_HEIGHT_IN_PIXELS,
	              CELL_WIDTH_IN_PIXELS - CELL_PADDING_WIDTH_IN_PIXELS * 2,
	              CELL_HEIGHT_IN_PIXELS - CELL_PADDING_HEIGHT_IN_PIXELS * 2,
	              color);
}

bool isSpecialFrame(int frames, double speed)
{
	if (speed == 0.0)
	{ return false; }
	static const int mod = static_cast<int>(TARGET_FPS / speed);
	assert(mod != 0);
	return (frames % mod) == 0;
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

void DrawSnakkeText()
{
	static constexpr int NAME_TEXT_SIZE[2] = {360, 100};
	static constexpr int NAME[2] = {
			BORDER_IN_PIXELS + LEFT_PANEL_WIDTH + BORDER_IN_PIXELS + GAME_WIDTH / 2 - NAME_TEXT_SIZE[0] / 2,
			SCREEN_HEIGHT / 2 - NAME_TEXT_SIZE[1] / 2};
	DrawText("Snakke", NAME[0], NAME[1], NAME_TEXT_SIZE[1], LIGHTGRAY);
}

void DrawScores(const Game &game)
{
	static constexpr int POSITION_VERT[2] = {BORDER_IN_PIXELS + 3,BORDER_IN_PIXELS + 28};
	static constexpr int POSITION_HOR = LEFT_PANEL_WIDTH + BORDER_IN_PIXELS * 3;
	DrawText(("Score: " + std::to_string(game.getScore())).c_str(), POSITION_HOR, POSITION_VERT[0], 20, BLACK);
	DrawText(("Hi-Score: " + std::to_string(BISSECTRA_HI_SCORE)).c_str(), POSITION_HOR, POSITION_VERT[1], 20, BLACK);
}

void DrawEverything(const Game &game)
{
	ClearBackground(RAYWHITE);
	DrawSnakkeText();
	game.draw();
	DrawScores(game);
	DrawLeftPanel();
	DrawBorder();
}