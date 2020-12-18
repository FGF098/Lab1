#pragma once

#include "Time.h"

class SecondsShift {

public:

	/// <summary>
	/// constructor for substraction, optimizing when calling
	/// </summary>
	/// <param name="reduction"></param>
	/// <param name="subtractor"></param>
	SecondsShift(int reduction, int subtractor);

	/// <summary>
	/// constructor for custom shift, optimizing when calling
	/// </summary>
	/// <param name="secondsShift"></param>
	SecondsShift(int secondsShiftParam);

	/// <returns>optimized seconds shift</returns>
	int getSecondsShift();

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