//
// Created by atsocs on 25/04/2020.
//

#ifndef OKAY_6D869709711A4E399E6AA38254D7750C_H
#define OKAY_6D869709711A4E399E6AA38254D7750C_H

#include "Constants.h"

class Game;

void DrawBorder();
void DrawLeftPanel();
void DrawCell(int x, int y, Color color, int leftPadding = (LEFT_PANEL_WIDTH + BORDER_IN_PIXELS));
bool isSpecialFrame(int frames, double speed);
int numDigits(int number);
void DrawSnakkeText();
void DrawScores(const Game &game);
void DrawEverything(const Game &game);

#endif //OKAY_6D869709711A4E399E6AA38254D7750C_H
