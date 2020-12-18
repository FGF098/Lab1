#pragma once

#include "Time.h"
#include "Date.h"
#include "TimeZone.h"

class DateTimeZone {

public:

	Time time;
	Date date;
	TimeZone zone;

	DateTimeZone();

	DateTimeZone(Time timeParam, Date dateParam, TimeZone zoneParam);

};
