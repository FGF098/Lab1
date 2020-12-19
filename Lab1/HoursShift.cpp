#include "HoursShift.h"
#include "Time.h"

int HoursShift::getDays() {
	return days;
}

int HoursShift::getHours() {
	return hours;
}

HoursShift::HoursShift(int hours_shift, int additional_minutes, int timeZoneHours) {
	hours = hours_shift + additional_minutes + timeZoneHours;
	Optimize();
}

HoursShift::HoursShift(int reduction, int subtractor, int additional_hours, int timeZoneHours) {
	hours = reduction - subtractor + additional_hours + timeZoneHours;
	Optimize();
}

void HoursShift::Optimize() {
	int hourRes, dayRes;
	if (hours >= 0) {
		dayRes = hours / HOURS_IN_DAY;
		hourRes = hours % HOURS_IN_DAY;
	}
	else {
		dayRes = hours / HOURS_IN_DAY - 1;
		hourRes = HOURS_IN_DAY - hours % HOURS_IN_DAY;
	}
	hours = hourRes;
	days = dayRes;
}