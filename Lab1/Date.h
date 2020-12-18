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

	/// <returns>number of month in this year</returns>
	Month getMonth();

	// TODO:
	/// <returns></returns>
	int getWeek();

	/// <returns>number of day in month</returns>
	int getDayMonth();

	// TODO:
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
	/// <returns><c>true</c> if year are intercalary, else <c>false</c></returns>
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

	/// <summary>
	/// 0 year is prohibited
	/// </summary>
	/// <param name="year"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool setYear(int yearParam);

	/// <param name="month"></param>
	void setMonth(Month monthParam);

	/// <summary>
	/// setter for day in month with chenking correct param based on current month
	/// </summary>
	/// <param name="day"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool setDayMonth(int dayParam);

	/// <summary>
	/// create empty date
	/// </summary>
	Date();


private:

	/// <summary>
	/// 0 year is prohibited
	/// </summary>
	int year;

	Month month;

	/// <summary>
	/// number of day in month
	/// </summary>
	int day;

};