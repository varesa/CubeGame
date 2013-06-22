/*
 * GameTimer.h
 *
 * Author: Esa Varemo
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
