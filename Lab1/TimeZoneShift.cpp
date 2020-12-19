#include "TimeZoneShift.h"

bool TimeZoneShift::getHalfHour() {
	return halfHour;
}

int TimeZoneShift::getShiftHour() {
	return shiftHour;
}

TimeZoneShift::TimeZoneShift(TimeZone reduction, TimeZone subtractor) {
	shiftHour = reduction.getHourShift() - subtractor.getHourShift();
	if (reduction.IsHalf() && !subtractor.IsHalf()) {
		halfHour = true;
	}
	else if (!reduction.IsHalf() && subtractor.IsHalf()) {
		halfHour = true;
		shiftHour--;
	}
	else {
		halfHour = false;
	}
}

TimeZoneShift::TimeZoneShift(int shiftHourParam, bool halfHourParam) {
	shiftHour = shiftHourParam;
	halfHour = halfHourParam;
}