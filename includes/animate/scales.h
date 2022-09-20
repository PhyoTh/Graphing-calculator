#ifndef SCALES_H
#define SCALES_H

const float SCREEN_WIDTH = 1400;
const float SCREEN_HEIGHT = 800;
const float WORK_PANEL = SCREEN_WIDTH * 4 / 5;
const float SIDE_BAR = SCREEN_WIDTH * 1 / 5;

const int SB_MOUSE_POSITION = 0;
const int SB_EQUATION = SB_MOUSE_POSITION + 2;
const int SB_DOMAINTEXT = SB_EQUATION + 1;
const int SB_DOMAIN = SB_DOMAINTEXT + 1;
const int SB_MOUSE_CLICKED = SB_DOMAIN + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED;

const int SB_HISTORYTEXT = SB_KEY_PRESSED + 3;
const int SB_HISTORY1 = SB_HISTORYTEXT + 2; // index 11
const int SB_HISTORY2 = SB_HISTORY1 + 2;
const int SB_HISTORY3 = SB_HISTORY2 + 2;
const int SB_HISTORY4 = SB_HISTORY3 + 2;
const int SB_HISTORY5 = SB_HISTORY4 + 2;
const int SB_HISTORY6 = SB_HISTORY5 + 2;
const int SB_HISTORY7 = SB_HISTORY6 + 2;
const int SB_HISTORY8 = SB_HISTORY7 + 2;
const int SB_HISTORY9 = SB_HISTORY8 + 2;

#endif
