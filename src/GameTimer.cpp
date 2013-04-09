/*
 * Timer.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: esa
 */

#include <GL/glut.h>

#include "GameTimer.h"


GameTimer::GameTimer() {
	lastTime = glutGet(GLUT_ELAPSED_TIME);
}

long GameTimer::getTimeAndReset() {
	long timeSince = glutGet(GLUT_ELAPSED_TIME) - lastTime;

	lastTime = glutGet(GLUT_ELAPSED_TIME);
	return timeSince;
}
