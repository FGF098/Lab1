#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/DateShift.h"

#include "../Lab1/Date.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestDateShift)
	{
		TEST_METHOD(ResultTest)
		{
			Date temp1_1 = Date(2019, November, 29);
			Date temp1_2 = Date(2021, January, 2);

			DateShift res1_1 = DateShift(temp1_2, temp1_1, 0);
			DateShift res1_2 = DateShift(temp1_1, temp1_2, 0);

			Assert::IsTrue(res1_1.getFullDayShift() == 400);
			Assert::IsTrue(res1_2.getFullDayShift() == -400);
			
		}
	};
}