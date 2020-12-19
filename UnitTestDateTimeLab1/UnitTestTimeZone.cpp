#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/TimeZone.h"
// fixes error LNK 2019 (based on StackOverflow answer)
#include "../Lab1/TimeZone.cpp"

// for constants
#include "../Lab1/Time.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestTimeZone)
	{
	public:

		TEST_METHOD(DefaultConstructorTest)
		{
			TimeZone temp = TimeZone();
			bool sameHours = temp.getHourShift() == 0;
			Assert::IsTrue(sameHours && !temp.IsHalf());
		}

		TEST_METHOD(NormalConstructorTest)
		{
			int hours1 = 3;
			int hours2 = 4;
			TimeZone temp1 = TimeZone(hours1, true);
			TimeZone temp2 = TimeZone(hours2, false);
			bool sameHours1 = temp1.getHourShift() == hours1;
			bool sameHours2 = temp2.getHourShift() == hours2;
			Assert::IsTrue(sameHours1 && temp1.IsHalf() && sameHours2 && !temp2.IsHalf());
		}

		TEST_METHOD(NormarSetterTest)
		{
			int hours1 = 5;
			int hours2 = 6;
			TimeZone temp1;
			TimeZone temp2;
			bool valid1 = temp1.setTimeZone(hours1, true);
			bool valid2 = temp2.setTimeZone(hours2, false);
			bool sameHours1 = temp1.getHourShift() == hours1;
			bool sameHours2 = temp2.getHourShift() == hours2;
			Assert::IsTrue(valid1 && valid2 && sameHours1 && sameHours2 && temp1.IsHalf() && !temp2.IsHalf());
		}

		TEST_METHOD(Invalid24ConsructorTest)
		{
			int invalidHour = HOURS_IN_DAY;
			TimeZone temp = TimeZone(invalidHour, true);
			bool  sameHours = temp.getHourShift() == 0;
			Assert::IsTrue(sameHours && !temp.IsHalf());
		}

		TEST_METHOD(InvalidConsructorTest)
		{
			int invalidHour = HOURS_IN_DAY + 1;
			TimeZone temp = TimeZone(invalidHour, true);
			bool  sameHours = temp.getHourShift() == 0;
			Assert::IsTrue(sameHours && !temp.IsHalf());
		}

		TEST_METHOD(Invalid24SetterTest)
		{
			int invalidHour = HOURS_IN_DAY;
			TimeZone temp; 
			bool valid = temp.setTimeZone(invalidHour, true);
			bool sameHours = temp.getHourShift() == 0;
			Assert::IsTrue(sameHours && !temp.IsHalf() && !valid);
		}

		TEST_METHOD(InvalidSetterTest)
		{
			int invalidHour = HOURS_IN_DAY + 2;
			TimeZone temp;
			bool valid = temp.setTimeZone(invalidHour, true);
			bool sameHours = temp.getHourShift() == 0;
			Assert::IsTrue(sameHours && !temp.IsHalf() && !valid);
		}
	};
}