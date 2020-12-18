#pragma once

class TimeZone {

public:

	int getHourShift();

	/// <summary>
	/// represent a additional half a hour, used in some regions
	/// </summary>
	bool IsHalf();

	TimeZone();

	TimeZone(int hourParam, bool halfHourParam);

	bool setTimeZone(int hourShiftParam, bool halfHourParam);

private:

	int hourShift;

	/// <summary>
	/// represent a additional half a hour, used in some regions
	/// </summary>
	bool halfHour;

	/// <summary>
	/// valid area: 0 - 23
	/// </summary>
	/// <param name="hour"></param>
	/// <returns><c>true</c> if correct, else <c>false</c></returns>
	bool checkHourShift(int hourParam);

	void set0();
};