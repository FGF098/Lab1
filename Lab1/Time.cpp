#pragma once

#include "Time.h"

bool Time::check24(int param) {
	return ((param >= 0) && (param < 24));
}

bool Time::check60(int param) {
	return ((param >= 0) && (param < 60));
}

bool Time::checkAll(int hoursParam, int minutesParam, int secondsParam) {
	return checkHours(hoursParam) && checkMinutes(minutesParam) && checkSeconds(secondsParam);
}

bool Time::checkHours(int hours) {
	return check24(hours);
}

bool Time::checkMinutes(int minutes) {
	return check60(minutes);
}

bool Time::checkSeconds(int seconds) {
	return check60(seconds);
}

int Time::getHours() {
	return hours;
}

int Time::getMinutes() {
	return minutes;
}

int Time::getSeconds() {
	return seconds;
}

void Time::set0() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

bool Time::setHours(int hoursParam = 0) {
	if (check24(hoursParam)) {
		hours = hoursParam;
		return true;
	}
	else {
		return false;
	}
}

bool Time::setMinutes(int minutesParam = 0) {
	if (check60(minutesParam)) {
		minutes = minutesParam;
		return true;
	}
	else {
		return false;
	}
}

bool Time::setSeconds(int secondsParam = 0) {
	if (check60(secondsParam)) {
		seconds = secondsParam;
		return true;
	}
	else {
		return false;
	}
}

bool Time::setTime(int hoursParam = 0, int minutesParam = 0, int secondsParam = 0) {
	if (checkAll(hoursParam, minutesParam, secondsParam)) {
		hours = hoursParam;
		minutes = minutesParam;
		seconds = secondsParam;
		return true;
	}
	else {
		return false;
	}
}

Time::Time() {
	set0;
}

Time::Time(int hoursParam, int minutesParam, int secondsParam) {
	if (checkHours(hoursParam) && checkMinutes(minutesParam) && checkSeconds(secondsParam)) {
		hours = hoursParam;
		minutes = minutesParam;
		seconds = secondsParam;
	}
	else {
		set0();
	}
}