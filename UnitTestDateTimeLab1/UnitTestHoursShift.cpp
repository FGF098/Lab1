#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/HoursShift.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestHoursShift)
	{
		TEST_METHOD(CustomResultTest)
		{
			HoursShift res1 = HoursShift(21, 0, 0);
			HoursShift res2 = HoursShift(-2, 0, 0);
			HoursShift res3 = HoursShift(27, 0, 0);
			HoursShift res4 = HoursShift(-27, 0, 0);

			Assert::IsTrue(res1.getHours() == 21);
			Assert::IsTrue(res1.getDays() == 0);

			Assert::IsTrue(res3.getHours() == 3);
			Assert::IsTrue(res3.getDays() == 1);

			Assert::IsTrue(res2.getHours() == 22);
			Assert::IsTrue(res2.getDays() == -1);

			Assert::IsTrue(res4.getHours() == 21);
			Assert::IsTrue(res4.getDays() == -2);
		}

		TEST_METHOD(reductionResultTest)
		{
			HoursShift res1 = HoursShift(12, 2, 0, 0);
			HoursShift res2 = HoursShift(2, 14, 0, 0);

			Assert::IsTrue(res1.getHours() == 10);
			Assert::IsTrue(res1.getDays() == 0);

			Assert::IsTrue(res2.getHours() == 12);
			Assert::IsTrue(res2.getDays() == -1);
		}
	};
}