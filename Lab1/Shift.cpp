#include "Shift.h"

#include "TimeZoneShift.h"
#include "TimeShift.h"
#include "DateShift.h"

int Shift::getDayShift() {
	return dayShift;
}

Time Shift::getTimeShift() {
	return timeShift;
}

Shift::Shift(DateTimeZone reduction, DateTimeZone subtractor) {
	TimeZoneShift timeZone = TimeZoneShift(reduction.zone, subtractor.zone);
	TimeShift time = TimeShift(reduction.time, subtractor.time, timeZone);
	DateShift date = DateShift(reduction.date, subtractor.date, time.getAdditionalDay());
	dayShift = date.getFullDayShift();
	timeShift = time.getTimeShift();
}