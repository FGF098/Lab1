#include "SecondsShift.h"

#include "Time.h"

int SecondsShift::getMinutes() {
	return minutes;
}

int SecondsShift::getSecondsShift() {
	return seconds;
}

void SecondsShift::Optimize() {
	if (seconds >= 0) {
		minutes = seconds / MINUTES_AND_SECONDS;
		seconds = seconds % MINUTES_AND_SECONDS;
	}
	else {
		while (seconds < 0) {
			seconds += MINUTES_AND_SECONDS;
			minutes--;
		}
	}
}

SecondsShift::SecondsShift(int reduction, int subtractor) {
	seconds = reduction - subtractor;
	Optimize();
}

SecondsShift::SecondsShift(int secondsShiftParam) {
	seconds = secondsShiftParam;
	Optimize();
}