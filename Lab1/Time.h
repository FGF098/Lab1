#pragma once

#include <string.h>

class Time {

public:

	/// <summary>
	/// getter for hours.
	/// <c>int hours = example.getHours();</c>
	/// </summary>
	/// <returns><c>int hours</c></returns>
	int getHours();

	/// <summary>
	/// getter for minutes.
	/// <c>int hours = example.getMinutes();</c>
	/// </summary>
	/// <returns><c>int minutes</c></returns>
	int getMinutes();

	/// <summary>
	/// getter for seconds.
	/// <c>int hours = example.getSeconds();</c>
	/// </summary>
	/// <returns><c>int seconds</c></returns>
	int getSeconds();

	/// <summary>
	/// setter for hours with checking correct value
	/// </summary>
	/// <param name="hours"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool setHours(int hours = 0);

	/// <summary>
	/// setter for minutes checking correct value
	/// </summary>
	/// <param name="minutes"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool setMinutes(int minutes = 0);

	/// <summary>
	/// setter for seconds checking correct value
	/// </summary>
	/// <param name="seconds"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool setSeconds(int seconds = 0);

	/// <summary>
	/// setter for time checking correct value
	/// </summary>
	/// <param name="hours"></param>
	/// <param name="minutes"></param>
	/// <param name="seconds"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool setTime(int hours = 0, int minutes = 0, int seconds = 0);

	/// <summary>
	/// setting current time (machine time)
	/// </summary>
	void setCurrent();

private:

	int hours;
	int minutes;
	int seconds;

	/// <summary>
	/// cheching correct value of hours
	/// </summary>
	/// <param name="hours"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkHours(int hours);

	/// <summary>
	/// cheching correct value of minutes
	/// </summary>
	/// <param name="minutes"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkMinutes(int minutes);

	/// <summary>
	/// cheching correct value of seconds
	/// </summary>
	/// <param name="seconds"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkSeconds(int seconds);

	/// <summary>
	/// cheching value 0 - 59
	/// </summary>
	/// <param name="param"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool check60(int param);

	/// <summary>
	/// cheching value 0 - 11
	/// </summary>
	/// <param name="param"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool check12(int param);
};