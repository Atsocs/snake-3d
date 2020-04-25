#include <iostream>
#include "Constants.h"
#include "okay.h"
#include "MovesQueue.h"
#include "raylib.h"
#include "Snake.h"

int main(int, char**)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = SCREEN_WIDTH;
	const int screenHeight = SCREEN_HEIGHT;

	int frames{0};
	MovesQueue movesQueue{};
	Snake snake{12};
	snake.turnTo(DIR_UP, false);
	snake.move(false);	snake.move(false);
	snake.turnTo(DIR_LEFT, false);
	snake.move(false);	snake.move(false);
	snake.move(false);	snake.move(false);
	snake.turnTo(DIR_UP, false);
	snake.turnTo(DIR_RIGHT, false);
	InitWindow(screenWidth, screenHeight, "Snakke");

	SetTargetFPS(TARGET_FPS);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		handleMoveKeys(movesQueue);
		if (isSpecialFrame(frames, snake.getSpeed()))
		{
			if (movesQueue.empty())
			{
				snake.move();
			}
			else
			{
				snake.turnTo(movesQueue.getMove());
			}
		}
		++frames;
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Snakke", GetScreenWidth() / 2 - 185, GetScreenHeight() / 2 - 50, 100, LIGHTGRAY);

		snake.draw();

		DrawBorder();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}