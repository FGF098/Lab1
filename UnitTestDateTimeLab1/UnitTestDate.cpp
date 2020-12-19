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

	};
}