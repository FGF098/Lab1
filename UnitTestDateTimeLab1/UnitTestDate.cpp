#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/Date.h"
// fixes error LNK 2019 (based on StackOverflow answer)
#include "../Lab1/Date.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(DateUnitTest)
	{
	public:

		TEST_METHOD(DefaultConstructorTest)
		{
			Date temp = Date();
			bool sameYear = temp.getYear() == START_YEAR;
			bool sameMonth = temp.getMonth() == START_MONTH;
			bool sameDay = temp.getDayMonth() == START_DAY;
			Assert::IsTrue(sameYear && sameMonth && sameDay);
		}

		TEST_METHOD(NormalConstructorTest)
		{
			int day = 3;
			Month month = September;
			int year = 1994;

			Date temp = Date(year, month, day);

			bool sameYear = temp.getYear() == year;
			bool sameMonth = temp.getMonth() == month;
			bool sameDay = temp.getDayMonth() == day;

			Assert::IsTrue(sameYear && sameMonth && sameDay);
		}

		TEST_METHOD(NormalSetterTest)
		{
			int day = 4;
			Month month = May;
			int year = 1995;

			Date temp;
			temp.SetDate(year, month, day);

			bool sameYear = temp.getYear() == year;
			bool sameMonth = temp.getMonth() == month;
			bool sameDay = temp.getDayMonth() == day;

			Assert::IsTrue(sameYear && sameMonth && sameDay);
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

			bool sameYear1 = temp1.getYear() == START_YEAR;
			bool sameMonth1 = temp1.getMonth() == START_MONTH;
			bool sameDay1 = temp1.getDayMonth() == START_DAY;
			bool same1 = sameYear1 && sameMonth1 && sameDay1;

			bool sameYear2 = temp2.getYear() == START_YEAR;
			bool sameMonth2 = temp2.getMonth() == START_MONTH;
			bool sameDay2 = temp2.getDayMonth() == START_DAY;
			bool same2 = sameYear2 && sameMonth2 && sameDay2;

			bool sameYear3 = temp3.getYear() == START_YEAR;
			bool sameMonth3 = temp3.getMonth() == START_MONTH;
			bool sameDay3 = temp3.getDayMonth() == START_DAY;
			bool same3 = sameYear3 && sameMonth3 && sameDay3;

			Assert::IsTrue(same1 && same2 && same3);
		}
	};
}