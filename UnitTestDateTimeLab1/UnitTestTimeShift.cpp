#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/TimeShift.h"
// fixes error LNK 2019 (based on StackOverflow answer)
#include "../Lab1/TimeShift.cpp"
#include "../Lab1/HoursShift.h"
#include "../Lab1/HoursShift.cpp"
#include "../Lab1/MinutesShift.h"
#include "../Lab1/MinutesShift.cpp"
#include "../Lab1/SecondsShift.h"
#include "../Lab1/SecondsShift.cpp"
#include "../Lab1/TimeZoneShift.h"
#include "../Lab1/Time.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestTimeShift)
	{
		TEST_METHOD(ResultTest)
		{
			TimeZoneShift tempZone1 = TimeZoneShift(0, false);
			TimeZoneShift tempZone2 = TimeZoneShift(2, true);

			Time tempTime1 = Time();
			Time tempTime2 = Time(22, 4, 3);
			Time tempTime3 = Time(4, 17, 8);

			TimeShift dif1 = TimeShift(tempTime2, tempTime1, tempZone2);
			TimeShift dif2 = TimeShift(tempTime3, tempTime2, tempZone1);

			Time res1 = dif1.getTimeShift();
			Time res2 = dif2.getTimeShift();

			Assert::IsTrue(dif1.getAdditionalDay() == 1);
			Assert::IsTrue(res1.getHours() == 0);
			Assert::IsTrue(res1.getMinutes() == 34);
			Assert::IsTrue(res1.getSeconds() == 3);

			Assert::IsTrue(dif2.getAdditionalDay() == -1);
			Assert::IsTrue(res2.getMinutes() == 13);
			Assert::IsTrue(res2.getSeconds() == 5);
			Assert::IsTrue(res2.getHours() == 6);
		}
	};
}