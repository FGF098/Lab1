#include "SecondsShift.h"

int SecondsShift::getMinutes() {
	return minutes;
}

int SecondsShift::getSecondsShift() {
	return seconds;
}

void SecondsShift::Optimize() {
	int secRes, minRes;
	if (seconds >= 0) {
		minRes = seconds / MINUTES_AND_SECONDS;
		secRes = seconds % MINUTES_AND_SECONDS;
	}
	else {
		minRes = seconds / MINUTES_AND_SECONDS - 1;
		secRes = MINUTES_AND_SECONDS - seconds % MINUTES_AND_SECONDS;
	}
	seconds = secRes;
	minutes = minRes;
}

SecondsShift::SecondsShift(int reduction, int subtractor) {
	seconds = reduction - subtractor;
	Optimize();
}

SecondsShift::SecondsShift(int secondsShiftParam) {
	seconds = secondsShiftParam;
	Optimize();
}