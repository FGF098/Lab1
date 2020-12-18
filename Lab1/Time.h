#pragma once

const int HOURS_IN_DAY = 24;
const int MINUTES_AND_SECONDS = 60;

/// <summary>
/// class for standart solar day with hours, minutes and seconds
/// </summary>
class Time {

public:

	/// <summary>
	/// getter for hours
	/// </summary>
	/// <returns><c>int hours</c></returns>
	int getHours();

	/// <summary>
	/// getter for minutes
	/// </summary>
	/// <returns><c>int minutes</c></returns>
	int getMinutes();

	/// <summary>
	/// getter for seconds
	/// </summary>
	/// <returns><c>int seconds</c></returns>
	int getSeconds();

	/// <summary>
	/// setter for time with checking correct value
	/// </summary>
	/// <param name="hours"></param>
	/// <param name="minutes"></param>
	/// <param name="seconds"></param>
	/// <returns><c>true</c> if correct, else <c>false</c>; set time if all params are correct</returns>
	bool setTime(int hoursParam = 0, int minutesParam = 0, int secondsParam = 0);

	/// <summary>
	/// Creates zero time
	/// </summary>
	Time();

	/// <summary>
	/// Creates given time if all params are correct, else creates zero time
	/// </summary>
	/// <param name="hours"></param>
	/// <param name="minutes"></param>
	/// <param name="seconds"></param>
	Time(int hoursParam, int minutesParam, int secondsParam);

private:

	int hours;

	int minutes;

	int seconds;

	/// <summary>
	/// cheching correct value of hours
	/// </summary>
	/// <param name="hours"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkHours(int hoursParam);

	/// <summary>
	/// cheching correct value of minutes
	/// </summary>
	/// <param name="minutes"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkMinutes(int minutesParam);

	/// <summary>
	/// cheching correct value of seconds
	/// </summary>
	/// <param name="seconds"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkSeconds(int secondsParam);

	bool checkAll(int hoursParam, int minutesParam, int secondsParam);

	/// <summary>
	/// cheching value 0 - 59
	/// </summary>
	/// <param name="param"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool check60(int param);

	/// <summary>
	/// cheching value 0 - 23
	/// </summary>
	/// <param name="param"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool check24(int param);

	/// <summary>
	/// Reset to zero time
	/// </summary>
	void set0();
};