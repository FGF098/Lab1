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
		minRes = seconds / 60;
		secRes = seconds % 60;
	}
	else {
		minRes = seconds / 60 - 1;
		secRes = 60 - seconds % 60;
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