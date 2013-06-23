/*
 * Main.h
 *
 * Author: Esa Varemo
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "GameTimer.h"
#include "GameState.h"
#include "Game.h"

class Main
{
public:
    Main();
    static int main(int argc, char **argv);

private:
    static GameTimer *timer;
    static Game *game;
    static bool* spKeys;

    static void initGLUT(int argc, char **argv);
    static void changeSize(int w, int h);
    static void renderScene();
    static void specialPressed(int key, int x, int y);
    static void specialUp(int key, int x, int y);
};

#endif // MAIN_H_
