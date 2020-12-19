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
		if (reduction.getMonth() > subtractor.getMonth()) {
			int daysBetween = 0;
			for (int i = subtractor.getMonth() + 1; i < reduction.getMonth(); i++) {
				daysBetween += reduction.daysInMonth((Month)i);
			}
			fullDayShift = reduction.getDayMonth() + daysBetween + (subtractor.daysInMonth() - subtractor.getDayMonth());
		}
		else if (reduction.getMonth() == subtractor.getMonth()) {
			fullDayShift = reduction.getDayMonth() - subtractor.getDayMonth();
		}
		else {
			int daysBetween = 0;
			for (int i = reduction.getMonth() + 1; i < subtractor.getMonth(); i++) {
				daysBetween += reduction.daysInMonth((Month)i);
			}
			fullDayShift = -((reduction.daysInMonth() - reduction.getDayMonth()) + daysBetween + subtractor.getDayMonth());
		}
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