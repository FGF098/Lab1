#pragma once

#include "Time.h"
#include "TimeZoneShift.h"

/// <summary>
/// class for a shift of a time with time zone shift
/// </summary>
class TimeShift {
public:

	/// <summary>
	/// creater reduction of two time moments
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	/// <param name="zone shift"></param>
	TimeShift(Time reduction, Time subtractor, TimeZoneShift zoneShift);

	Time getTimeShift();

	int getAdditionalDay();

private:

	Time timeShift;

	int additionalDay;
};