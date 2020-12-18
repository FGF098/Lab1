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

	bool setTimeZone(int hourParam, bool halfHourParam);

private:

	int hourShift;

	/// <summary>
	/// represent a additional half a hour, used in some regions
	/// </summary>
	bool halfHour;

};