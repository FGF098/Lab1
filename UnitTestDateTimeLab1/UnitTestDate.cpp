#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/Date.h"
// fixes error LNK 2019 (based on StackOverflow answer)
#include "../Lab1/Date.cpp"
#include "../Lab1/DateShift.cpp"

// for constants
#include "../Lab1/Week.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestDate)
	{
	public:

		TEST_METHOD(DefaultConstructorTest)
		{
			Date temp;

			Assert::IsTrue(temp.getYear() == START_YEAR);
			Assert::IsTrue(temp.getMonth() == START_MONTH);
			Assert::IsTrue(temp.getDayMonth() == START_DAY);
			Assert::IsTrue(temp.getDayWeek() == START_WEEK);
		}

		TEST_METHOD(NormalConstructorTest)
		{
			int day = 14;
			Month month = December;
			int year = 2020;
			Week dayWeek = Monday;

			Date temp = Date(year, month, day);

			Assert::IsTrue(temp.getYear() == year);
			Assert::IsTrue(temp.getMonth() == month);
			Assert::IsTrue(temp.getDayMonth() == day);
			Assert::IsTrue(temp.getDayWeek() == dayWeek);
		}

		TEST_METHOD(NormalSetterTest)
		{
			int day = 15;
			Month month = December;
			int year = 2020;
			Week dayWeek = Tuesday;

			Date temp;
			temp.SetDate(year, month, day);

			Assert::IsTrue(temp.getYear() == year);
			Assert::IsTrue(temp.getMonth() == month);
			Assert::IsTrue(temp.getDayMonth() == day);
			Assert::IsTrue(temp.getDayWeek() == dayWeek);
		}

		TEST_METHOD(InvalidConstructorTest)
		{
			int invalidDay = 33;
			int invalidYear = START_YEAR - 2;

			int validDay = 5;
			Month validMonth = March;
			int validYear = 2077;

			Date temp1 = Date(invalidYear, validMonth, validDay);
			Date temp2 = Date(validYear, validMonth, invalidDay);
			Date temp3 = Date(invalidYear, validMonth, invalidDay);

			Assert::IsTrue(temp1.getYear() == START_YEAR);
			Assert::IsTrue(temp1.getMonth() == START_MONTH);
			Assert::IsTrue(temp1.getDayMonth() == START_DAY);

			Assert::IsTrue(temp2.getYear() == START_YEAR);
			Assert::IsTrue(temp2.getMonth() == START_MONTH);
			Assert::IsTrue(temp2.getDayMonth() == START_DAY);

			Assert::IsTrue(temp3.getYear() == START_YEAR);
			Assert::IsTrue(temp3.getMonth() == START_MONTH);
			Assert::IsTrue(temp3.getDayMonth() == START_DAY);
		}

		TEST_METHOD(InvalidSetterTest)
		{
			int invalidDay = 34;
			int invalidYear = START_YEAR - 3;

			int validDay = 6;
			Month validMonth = March;
			int validYear = 2020;

			Date temp1;
			Date temp2;
			Date temp3;

			Assert::IsFalse(temp1.SetDate(invalidYear, validMonth, validDay));
			Assert::IsFalse(temp2.SetDate(validYear, validMonth, invalidDay));
			Assert::IsFalse(temp3.SetDate(invalidYear, validMonth, invalidDay));

			Assert::IsTrue(temp1.getYear() == START_YEAR);
			Assert::IsTrue(temp1.getMonth() == START_MONTH);
			Assert::IsTrue(temp1.getDayMonth() == START_DAY);

			Assert::IsTrue(temp2.getYear() == START_YEAR);
			Assert::IsTrue(temp2.getMonth() == START_MONTH);
			Assert::IsTrue(temp2.getDayMonth() == START_DAY);

			Assert::IsTrue(temp3.getYear() == START_YEAR);
			Assert::IsTrue(temp3.getMonth() == START_MONTH);
			Assert::IsTrue(temp3.getDayMonth() == START_DAY);
		}

		TEST_METHOD(LeapYearTest)
		{
			Assert::IsTrue(Date::isYearLeap(2000));
			Assert::IsFalse(Date::isYearLeap(2100));
			Assert::IsTrue(Date::isYearLeap(2004));
			Assert::IsFalse(Date::isYearLeap(2003));
		}

		TEST_METHOD(Feb29Test)
		{
			int day = 29;
			Month month = February;
			Date temp;

			Assert::IsTrue(temp.SetDate(2000, month, day));
			Assert::IsFalse(temp.SetDate(2100, month, day));
			Assert::IsTrue(temp.SetDate(2004, month, day));
			Assert::IsFalse(temp.SetDate(2003, month, day));
		}

		TEST_METHOD(DaysInMonthtest)
		{
			Assert::IsTrue(Date::daysInMonth(February, 2020) == 29);
			Assert::IsTrue(Date::daysInMonth(February, 2021) == 28);
			Assert::IsTrue(Date::daysInMonth(September, 2019) == 30);
			Assert::IsTrue(Date::daysInMonth(August, 2022) == 31);
		}

		TEST_METHOD(DaysOfYearTest)
		{
			Assert::IsTrue(Date::getDaysOfYear(2020) == 366);
			Assert::IsTrue(Date::getDaysOfYear(2000) == 366);
			Assert::IsTrue(Date::getDaysOfYear(2001) == 365);
			Assert::IsTrue(Date::getDaysOfYear(2100) == 365);
		}

		TEST_METHOD(DaysToNextAndPastTest)
		{
			Date temp1 = Date(2020, November, 29);
			Date temp2 = Date(2020, March, 3);

			Assert::IsTrue(temp1.getDaysToNext() == 32);
			Assert::IsTrue(temp2.getDaysToPast() == 63);
		}
	};
}