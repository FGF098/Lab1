#pragma once

#include "Week.h"
#include "Month.h"

/// <summary>
/// class for standart gregorian date
/// </summary>
class Date {

public:

	/// <returns>number of year, below zero if B.C.</returns>
	int getYear();

	/// <returns>number of month in year</returns>
	Month getMonth();

	/// <returns></returns>
	int getWeek();

	/// <returns>number of day in month</returns>
	int getDayMonth();

	/// <returns>number of a day in week</returns>
	Week getDayWeek();

	/// <summary>
	/// is this year intercalary
	/// </summary>
	/// <returns><c>true</c> if leap year, else <c>false</c></returns>
	bool IsYearLeap();

	/// <summary>
/// if <c>year % 4 == 0</c> -> intercalary year
/// if <c>year % 100 == 0</c> -> not intercalary year
/// if <c>year % 400 == 0</c> -> intercalary year
/// if <c>year % 4 != 0</c> -> not intercalary year
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
	static bool IsYearLeap(int yearParam);

	/// <returns>days in current month and year</returns>
	int daysInMonth();

	/// <param name="month"></param>
	/// <returns>days in given month and current year</returns>
	int daysInMonth(Month monthParam);

	/// <param name="month"></param>
	/// <param name="year"></param>
	/// <returns>days in month in given month and year</returns>
	static int daysInMonth(Month monthParam, int yearParam);

private:

	int year;

	Month month;

	/// <summary>
	/// number of day in month
	/// </summary>
	int day;

};