#include <iostream>
#include "Constants.h"
#include "okay.h"
#include "MovesQueue.h"
#include "raylib.h"
#include "Snake.h"
#include "Game.h"

int main(int, char **)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = SCREEN_WIDTH;
	const int screenHeight = SCREEN_HEIGHT;

	int frames{0};
	MovesQueue movesQueue{};
	Game game{Snake{}};
	InitWindow(screenWidth, screenHeight, "Snakke");

	SetTargetFPS(TARGET_FPS);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		handleMoveKeys(movesQueue);
		if (isSpecialFrame(frames, game.getSnakeSpeed()))
		{
#ifdef SNAKKE_DEBUG
			if (game.alive())
			{ std::cout << "Before/" << game << std::endl; }
#endif
			if (movesQueue.empty())
			{
				game.moveSnake();
			}
			else
			{
				game.turnSnakeTo(movesQueue.getMove());
			}
#ifdef SNAKKE_DEBUG
//			if (game.alive())
//			{ std::cout << "After/" << game << std::endl; }
#endif
		}
		++frames;
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		DrawEverything(game);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}