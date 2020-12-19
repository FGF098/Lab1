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
	if (hours >= 0) {
		days = hours / HOURS_IN_DAY;
		hours = hours % HOURS_IN_DAY;
	}
	else {
		while (hours < 0)
		{
			hours += HOURS_IN_DAY;
			days--;
		}
	}
}