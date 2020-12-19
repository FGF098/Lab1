#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/TimeZoneShift.h"
// fixes error LNK 2019 (based on StackOverflow answer)
#include "../Lab1/TimeZoneShift.cpp"

// for constants
#include "../Lab1/TimeZone.h"
// fixes error LNK 2019 (based on StackOverflow answer)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(TimeZoneShiftTest)
	{
		TEST_METHOD(ResultTest)
		{
			TimeZone temp1 = TimeZone(2, true);
			TimeZone temp2 = TimeZone(2, false);
			TimeZone temp3 = TimeZone(4, true);
			TimeZone temp4 = TimeZone(4, false);

			TimeZoneShift res1 = TimeZoneShift(temp1, temp2);
			TimeZoneShift res2 = TimeZoneShift(temp1, temp3);
			TimeZoneShift res3 = TimeZoneShift(temp1, temp4);
			TimeZoneShift res4 = TimeZoneShift(temp2, temp1);
			TimeZoneShift res5 = TimeZoneShift(temp2, temp3);
			TimeZoneShift res6 = TimeZoneShift(temp2, temp4);
			TimeZoneShift res7 = TimeZoneShift(temp3, temp1);
			TimeZoneShift res8 = TimeZoneShift(temp3, temp2);
			TimeZoneShift res9 = TimeZoneShift(temp3, temp4);
			TimeZoneShift res10 = TimeZoneShift(temp4, temp1);
			TimeZoneShift res11 = TimeZoneShift(temp4, temp2);
			TimeZoneShift res12 = TimeZoneShift(temp4, temp3);

			Assert::IsTrue(res1.getShiftHour() == 0);
			Assert::IsTrue(res1.getHalfHour());

			Assert::IsTrue(res2.getShiftHour() == -2);
			Assert::IsFalse(res2.getHalfHour());

			Assert::IsTrue(res3.getShiftHour() == -2);
			Assert::IsTrue(res3.getHalfHour());

			Assert::IsTrue(res4.getShiftHour() == -1);
			Assert::IsTrue(res4.getHalfHour());

			Assert::IsTrue(res5.getShiftHour() == -3);
			Assert::IsTrue(res5.getHalfHour());

			Assert::IsTrue(res6.getShiftHour() == -2);
			Assert::IsFalse(res6.getHalfHour());

			Assert::IsTrue(res7.getShiftHour() == 2);
			Assert::IsFalse(res7.getHalfHour());

			Assert::IsTrue(res8.getShiftHour() == 2);
			Assert::IsTrue(res8.getHalfHour());

			Assert::IsTrue(res9.getShiftHour() == 0);
			Assert::IsTrue(res9.getHalfHour());

			Assert::IsTrue(res10.getShiftHour() == 1);
			Assert::IsTrue(res10.getHalfHour());

			Assert::IsTrue(res11.getShiftHour() == 2);
			Assert::IsFalse(res11.getHalfHour());

			Assert::IsTrue(res12.getShiftHour() == -1);
			Assert::IsTrue(res12.getHalfHour());
		}
	};
}