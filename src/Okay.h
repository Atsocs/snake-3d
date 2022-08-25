//
// Created by atsocs on 25/04/2020.
//

#ifndef OKAY_5CCD0C7B8D764E2BAFC7A80F8B54DCB0_H
#define OKAY_5CCD0C7B8D764E2BAFC7A80F8B54DCB0_H

#include "hardcoded/Constants.h"

class Game;

void DrawBorder();
void DrawLeftPanel();
void DrawCell(int x, int y, Color color, int leftPadding = (LEFT_PANEL_WIDTH + BORDER_IN_PIXELS));
bool isSpecialFrame(int frames, double speed);
int numDigits(int number);
void DrawSnakkeText();
void DrawScores(const Game &game);
void DrawEverything(const Game &game);

#endif //OKAY_5CCD0C7B8D764E2BAFC7A80F8B54DCB0_H
