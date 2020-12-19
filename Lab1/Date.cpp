#include "Date.h"

bool Date::IsYearLeap(int yearParam) {
	bool res;
	res = yearParam % 4 == 0;
	if (res && yearParam % 100 == 0) {
		res = false;
	}
	if (res && yearParam % 400 == 0) {
		res = true;
	}
	return res;
}

bool Date::IsYearLeap() {
	return Date::IsYearLeap(this->year);
}

int Date::daysInMonth(Month monthParam, int yearParam) {
	switch (monthParam){
	case January:
	case March:
	case May:
	case July:
	case August:
	case October:
	case December:
		return 31;
		break;
	case April:
	case June:
	case September:
	case November:
		return 30;
		break;
	case February:
		if (IsYearLeap(yearParam)) {
			return 29;
		}
		else {
			return 28;
		}
		break;
	default:
		throw "Invalid month";
		return -1;
	}

}

int Date::daysInMonth(Month monthParam) {
	return daysInMonth(monthParam, this->year);
}

int Date::daysInMonth() {
	return daysInMonth(this->month, this->year);
}

int Date::getYear() {
	return year;
}

Month Date::getMonth() {
	return month;
}

int Date::getDayMonth() {
	return day;
}

int Date::getDaysToNext(Date dateParam) {
	int res = daysInMonth(dateParam.month, dateParam.year) - dateParam.day;
	for (Month i = December; i > dateParam.month; i = (Month)(i - 1)) {
		res += daysInMonth(i, dateParam.year);
	}
	return res;
}

int Date::getDaysToNext() {
	return getDaysToNext(*this);
}

int Date::getDaysToPast(Date dateParam) {
	int res = dateParam.day;
	for (Month i = January; i < dateParam.month; i = (Month)(i + 1)) {
		res += daysInMonth(i, dateParam.year);
	}
	return res;
}

int Date::getDaysToPast() {
	return getDaysToPast(*this);
}

int Date::getDaysOfYear(int yearParam) {
	if (IsYearLeap(yearParam)) {
		return 366;
	}
	else {
		return 365;
	}
}

int Date::getDaysOfYear() {
	return getDaysOfYear(this->year);
}

Date::Date() {
	set0();
}

Date::Date(int yearParam, Month monthParam, int dayParam) {
	if ((yearParam > START_YEAR) || (yearParam == START_YEAR && monthParam > START_MONTH) ||
		(yearParam == START_YEAR && monthParam == START_MONTH && dayParam >= START_DAY)) {
		year = yearParam;
		month = monthParam;
		day = dayParam;
	}
	else {
		set0();
	}
}

bool Date::SetDate(int yearParam, Month monthParam, int dayParam) {
	if ((yearParam > START_YEAR) || (yearParam == START_YEAR && monthParam > START_MONTH) ||
		(yearParam == START_YEAR && monthParam == START_MONTH && dayParam >= START_DAY)) {
		year = yearParam;
		month = monthParam;
		day = dayParam;
		return true;
	}
	else {
		return false;
	}
}

void Date::set0() {
	year = START_YEAR;
	month = START_MONTH;
	day = START_DAY;
}

void Date::addDays(int additionalDays) {
	if (additionalDays < 0) {
		additionalDays = -additionalDays;
		reduDays(additionalDays);
	}
	else {
		while (additionalDays > getDaysToNext()) {
			additionalDays -= (getDaysToNext() + 1);
			year++;
			month = January;
			day = 1;
		}
		while (additionalDays > (daysInMonth() - day)) {
			additionalDays -= (daysInMonth() - day + 1);
			if (month == December) {
				month = January;
			}
			else {
				month = (Month)(month + 1);
			}
			day = 1;
		}
		day += additionalDays;
	}
}

void Date::reduDays(int reducedDays) {
	if (reducedDays < 0) {
		reducedDays = -reducedDays;
		addDays(reducedDays);
	}
	else {
		while (reducedDays > getDaysToPast()) {
			reducedDays -= (getDaysToPast() + 1);
			year--;
			month = January;
			day = 1;
		}
		while (reducedDays > day) {
			reducedDays -= (day + 1);
			if (month == January) {
				month = December;
			}
			else {
				month = (Month)(month - 1);
			}
			day = daysInMonth();
		}
		day -= reducedDays;
	}
}