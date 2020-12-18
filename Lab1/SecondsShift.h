#pragma once

#include "Time.h"

class SecondShift {

public:

	/// <summary>
	/// constructor for substraction
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	SecondShift(int reduction, int subtractor);

	/// <summary>
	/// construntor for custom shift
	/// </summary>
	/// <param name="secondShift"></param>
	SecondShift(int secondShiftParam);

	/// <summary>
	/// Optimizing when calling
	/// </summary>
	/// <returns>optimized seconds shift</returns>
	int getSecondsShift();

	/// <summary>
	/// Optimizing when calling
	/// </summary>
	/// <returns>minutes after optimizing</returns>
	int getMinutes();

	/// <summary>
	/// transform oversize seconds to minutes, seconds will be positive after
	/// </summary>
	void Optimize();

private:

	int seconds;

	/// <summary>
	/// default zero initialization
	/// </summary>
	int minutes = 0;
};