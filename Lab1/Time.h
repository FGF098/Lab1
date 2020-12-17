#pragma once

#include <string.h>

class Time {

public:

	/// <summary>
	/// getter for hours
	/// <c>int hours = example.getHours();</c>
	/// </summary>
	/// <returns></returns>
	int getHours();
	int getMinutes();
	int getSeconds();

	bool setHours(int hours);
	bool setMinutes(int minutes);
	bool setSeconds(int seconds);
	bool setTime(int hours, int minutes, int seconds);

	void setCurrent();

private:

	int hours;
	int minutes;
	int seconds;
};