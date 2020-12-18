#include "MinutesShift.h"

int MinutesShift::getHours() {
	return hours;
}

int MinutesShift::getMinutes() {
	return minutes;
}

MinutesShift::MinutesShift(int minutes_shift, int additional_minutes, bool halfHour) {
	int halfHourMinutes = 0;
	if (halfHour) {
		halfHourMinutes += MINUTES_AND_SECONDS / 2;
	}
	minutes = minutes_shift + additional_minutes + halfHourMinutes;
	Optimize();
}

MinutesShift::MinutesShift(int reduction, int subtractor, int additional_minutes, bool halfHour) {
	int halfHourMinutes = 0;
	if (halfHour) {
		halfHourMinutes += MINUTES_AND_SECONDS / 2;
	}
	minutes = reduction - subtractor + additional_minutes + halfHourMinutes;
	Optimize();
}

void MinutesShift::Optimize() {
	int hourRes, minRes;
	if (minutes >= 0) {
		hourRes = minutes / MINUTES_AND_SECONDS;
		minRes = minutes % MINUTES_AND_SECONDS;
	}
	else {
		hourRes = minutes / MINUTES_AND_SECONDS - 1;
		minRes = MINUTES_AND_SECONDS - minutes % MINUTES_AND_SECONDS;
	}
	hours = hourRes;
	minutes = minRes;
}