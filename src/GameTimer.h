/*
 * Timer.h
 *
 *  Created on: Jan 31, 2013
 *      Author: esa
 */

#ifndef TIMER_H_
#define TIMER_H_

class GameTimer {
	public:
	GameTimer();
	long getTimeAndReset();

	private:
	long lastTime;
};

#endif /* TIMER_H_ */
