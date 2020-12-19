#pragma once

#include "TimeZoneShift.h"

class HoursShift {

public:

	/// <returns>hours shift</returns>
	int getHours();

	/// <returns>extended days</returns>
	int getDays();

	/// <summary>
	/// Constuctor for substraction, optimizing when callling
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	/// <param name="additional hours from minutes shift"></param>
	/// <param name="hours from time zone shift"></param>
	HoursShift(int reduction, int subtractor, int additional_hours, int timeZoneHours);

	/// <summary>
	/// Constructor for custom creating
	/// </summary>
	/// <param name="hours shift"></param>
	/// <param name="additional hours from minutes shift"></param>
	/// <param name="hours from time zone shift"></param>
	HoursShift(int hours_shift, int additional_minutes, int timeZoneHours);

private:

	int hours;

	int days = 0;

	/// <summary>
	/// optimized hours will be positive
	/// </summary>
	void Optimize();

};