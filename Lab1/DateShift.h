#pragma once

#include "Date.h"

class DateShift {

public:

	/// <summary>
	/// constructor for reduction with additional days from time shift
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	/// <param name="additional days"></param>
	DateShift(Date reduction, Date subtractor, int additionalDays);


	/// <returns>full day shift</returns>
	int getFullDayShift();

private:

	/// <summary>
	/// reprezents all shift in days
	/// default 0 for preparing to summing
	/// </summary>
	int fullDayShift = 0;

};