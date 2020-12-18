#pragma once

#include "TimeZone.h"

class TimeZoneShift {

public: 

	TimeZoneShift(TimeZone reduction, TimeZone subtractor);

private:

	int shiftHour;

	/// <summary>
	/// always positive : -4 + 0,5
	/// </summary>
	bool halfHour;
};