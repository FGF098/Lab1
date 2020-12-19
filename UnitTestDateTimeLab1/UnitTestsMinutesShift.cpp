#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/MinutesShift.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestMinutesShift)
	{
		TEST_METHOD(CustomResultTest)
		{
			MinutesShift res1 = MinutesShift(21, 0, false);
			MinutesShift res2 = MinutesShift(-2, 0, false);
			MinutesShift res3 = MinutesShift(72, 0, false);
			MinutesShift res4 = MinutesShift(-72, 0, false);

			Assert::IsTrue(res1.getMinutes() == 21);
			Assert::IsTrue(res1.getHours() == 0);

			Assert::IsTrue(res3.getMinutes() == 12);
			Assert::IsTrue(res3.getHours() == 1);

			Assert::IsTrue(res2.getMinutes() == 58);
			Assert::IsTrue(res2.getHours() == -1);

			Assert::IsTrue(res4.getMinutes() == 48);
			Assert::IsTrue(res4.getHours() == -2);
		}

		TEST_METHOD(reductionResultTest)
		{
			MinutesShift res1 = MinutesShift(12, 2, 0, false);
			MinutesShift res2 = MinutesShift(2, 14, 0, false);

			Assert::IsTrue(res1.getMinutes() == 10);
			Assert::IsTrue(res1.getHours() == 0);

			Assert::IsTrue(res2.getMinutes() == 48);
			Assert::IsTrue(res2.getHours() == -1);
		}
	};
}