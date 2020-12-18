#pragma once

#include "TimeZone.h"

/// <summary>
/// shift for time zones
/// </summary>
class TimeZoneShift {

public: 

	/// <summary>
	/// difference between time zones, can't use it as operator-
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	TimeZoneShift(TimeZone reduction, TimeZone subtractor);
	
	/// <summary>
	/// Custom time zone shift
	/// </summary>
	/// <param name="shiftHour"></param>
	/// <param name="halfHour"></param>
	TimeZoneShift(int shiftHourParam, bool halfHourParam);

private:

	int shiftHour;

	/// <summary>
	/// always positive : -4 + 0,5
	/// </summary>
	bool halfHour;
};