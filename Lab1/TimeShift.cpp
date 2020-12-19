#include "TimeShift.h"

int TimeShift::getAdditionalDay() {
	return additionalDay;
}

Time TimeShift::getTimeShift() {
	return timeShift;
}

#include "SecondsShift.h"
#include "MinutesShift.h"
#include "HoursShift.h"

TimeShift::TimeShift(Time reduction, Time subtractor, TimeZoneShift zoneShift) {
	SecondsShift sec = SecondsShift(reduction.getSeconds(), subtractor.getSeconds());
	int seconds = sec.getSecondsShift();
	MinutesShift min = MinutesShift(reduction.getMinutes(), subtractor.getMinutes(), sec.getMinutes(), zoneShift.getHalfHour());
	int minutes = min.getMinutes();
	HoursShift hou = HoursShift(reduction.getHours(), subtractor.getHours(), min.getHours(), zoneShift.getShiftHour());
	int hours = hou.getHours();
	timeShift = Time(hours, minutes, seconds);
	additionalDay = hou.getDays();
}