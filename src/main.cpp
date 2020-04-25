#include "Constants.h"
#include "okay.h"
#include "MovesQueue.h"
#include "raylib.h"

int main(int, char**)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = SCREEN_WIDTH;
	const int screenHeight = SCREEN_HEIGHT;

	MovesQueue movesQueue{};
	InitWindow(screenWidth, screenHeight, "Snakke");

	SetTargetFPS(TARGET_FPS);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		handleMoveKeys(movesQueue);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Snakke", GetScreenWidth() / 2 - 185, GetScreenHeight() / 2 - 50, 100, LIGHTGRAY);

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