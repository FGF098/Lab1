#include "TimeZone.h"

#include "Time.h"

bool TimeZone::checkHourShift(int hourParam) {
	if (hourParam >= 0 && hourParam < HOURS_IN_DAY) {
		return true;
	}
	else {
		return false;
	}
}

int TimeZone::getHourShift() {
	return hourShift;
}

bool TimeZone::IsHalf() {
	return halfHour;
}

TimeZone::TimeZone() {
	set0();
}

TimeZone::TimeZone(int hourShiftParam, bool halfHourParam) {
	if (checkHourShift(hourShiftParam)) {
		hourShift = hourShiftParam;
		halfHour = halfHourParam;
	}
	else {
		set0();
	}
}

bool TimeZone::setTimeZone(int hourShiftParam, bool halfHourParam) {
	if (checkHourShift(hourShiftParam)) {
		hourShift = hourShiftParam;
		halfHour = halfHourParam;
		return true;
	}
	else {
		return false;
	}
}

void TimeZone::set0() {
	hourShift = 0;
	halfHour = 0;
}