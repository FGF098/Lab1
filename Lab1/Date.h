#pragma once

#include "Week.h"
#include "Month.h"

const int START_YEAR = 1582;
const Month START_MONTH = October;
const int START_DAY = 4;
const Week START_WEEK_DAY = Monday;

/// <summary>
/// class for standart gregorian date
/// </summary>
class Date {

public:

	/// <returns>number of year</returns>
	int getYear();

	/// <returns>number of month in this year</returns>
	Month getMonth();

	/// <returns>number of day in month</returns>
	int getDayMonth();

	/// <param name="date"></param>
	/// <returns>days to end of a year</returns>
	static int getDaysToNext(Date dateParam);

	/// <returns>days to end of a year for this date</returns>
	int getDaysToNext();

	/// <param name="date"></param>
	/// <returns>days from start of a year</returns>
	static int getDaysToPast(Date dateParam);

	/// <returns>days from start of a year for this date</returns>
	int getDaysToPast();

	/// <param name="year"></param>
	/// <returns>number of days in the year</returns>
	static int getDaysOfYear(int yearParam);

	/// <returns>number of days in the year for this date</returns>
	int getDaysOfYear();

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
	/// Creates START_DATE
	/// </summary>
	Date();

	/// <summary>
	/// creates given date if all params are correct, else creates START_DATE
	/// </summary>
	/// <param name="year"></param>
	/// <param name="month"></param>
	/// <param name="day"></param>
	Date(int yearParam, Month monthParam, int dayParam);

	/// <summary>
	/// changes to a given date if all params are correct
	/// </summary>
	/// <param name="yearParam"></param>
	/// <param name="monthParam"></param>
	/// <param name="dayParam"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool SetDate(int yearParam, Month monthParam, int dayParam);

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

	/// <summary>
	/// Reset to a START_DATE
	/// </summary>
	void set0();

	/// <summary>
	/// add given number of days to date
	/// parameter must be non-negative, else iverting and calling reduDays()
	/// </summary>
	/// <param name="additional days"></param>
	void addDays(int additionalDays);

	/// <summary>
	/// reduse given number of days to date
	/// parameter must be non-negative, else iverting and calling addDays()
	/// </summary>
	/// <param name="reduced days"></param>
	void reduDays(int reducedDays);
};