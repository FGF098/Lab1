#include "DateShift.h"
#include "Date.h"

DateShift::DateShift(Date reduction, Date subtractor, int additionalDays) {
	if (reduction.getYear() > subtractor.getYear()) {
		int daysBetween = 0;
		for (int i = subtractor.getYear() + 1; i < reduction.getYear(); i++) {
			daysBetween += Date::getDaysOfYear(i);
		}
		fullDayShift = reduction.getDaysToPast() + daysBetween + subtractor.getDaysToNext();
	}
	else if (reduction.getYear() == subtractor.getYear()) {
		fullDayShift = reduction.getDaysToPast() - subtractor.getDaysToPast();
	}
	else {
		int daysBetween = 0;
		for (int i = reduction.getYear() + 1; i < subtractor.getYear(); i++) {
			daysBetween += Date::getDaysOfYear(i);
		}
		fullDayShift = -(reduction.getDaysToNext() + daysBetween + subtractor.getDaysToPast());
	}
	fullDayShift += additionalDays;
}

int DateShift::getFullDayShift() {
	return fullDayShift;
}