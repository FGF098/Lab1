#pragma once

#include "TimeZoneShift.h"

class MinutesShift {
	
public:

	/// <returns>minutes shift</returns>
	int getMinutes();

	/// <returns>extended hours</returns>
	int getHours();

	/// <summary>
	/// Constuctor for substraction, optimizing when callling
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	/// <param name="additional minutes from seconds shift"></param>
	/// <param name="half of the hour from time zone shift"></param>
	MinutesShift(int reduction, int subtractor, int additional_minutes, bool halfHour);

	/// <summary>
	/// Constructor for custom creating
	/// </summary>
	/// <param name="minutes shift"></param>
	/// <param name="additional minutes"></param>
	/// <param name="half of the hour from time zone shift"></param>
	MinutesShift(int minutes_shift, int additional_minutes, bool halfHour);

private:

	int minutes;

	int hours = 0;

	/// <summary>
	/// optimized minutes will be positive
	/// </summary>
	void Optimize();

};