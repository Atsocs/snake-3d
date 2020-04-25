//
// Created by atsocs on 25/04/2020.
//

#include "okay.h"
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
