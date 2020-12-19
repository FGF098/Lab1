#pragma once

#include "DateTimeZone.h"
#include "Time.h"

class Shift {
public:

	/// <summary>
	/// function for reducing
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	Shift(DateTimeZone reduction, DateTimeZone subtractor);

	int getDayShift();

	Time getTimeShift();

private:

	int dayshift;

	/// <summary>
	/// This time wiil be non-negative
	/// </summary>
	Time timeShift;

};