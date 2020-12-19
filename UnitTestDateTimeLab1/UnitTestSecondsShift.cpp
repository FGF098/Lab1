#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/SecondsShift.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestSecondsShift)
	{
		TEST_METHOD(CustomResultTest)
		{
			SecondsShift res1 = SecondsShift(21);
			SecondsShift res2 = SecondsShift(-2);
			SecondsShift res3 = SecondsShift(72);
			SecondsShift res4 = SecondsShift(-72);

			Assert::IsTrue(res1.getSecondsShift() == 21);
			Assert::IsTrue(res1.getMinutes() == 0);

			Assert::IsTrue(res3.getSecondsShift() == 12);
			Assert::IsTrue(res3.getMinutes() == 1);

			Assert::IsTrue(res2.getSecondsShift() == 58);
			Assert::IsTrue(res2.getMinutes() == -1);

			Assert::IsTrue(res4.getSecondsShift() == 48);
			Assert::IsTrue(res4.getMinutes() == -2);
		}

		TEST_METHOD(reductionResultTest)
		{
			SecondsShift res1 = SecondsShift(12, 2);
			SecondsShift res2 = SecondsShift(2, 14);

			Assert::IsTrue(res1.getSecondsShift() == 10);
			Assert::IsTrue(res1.getMinutes() == 0);

			Assert::IsTrue(res2.getSecondsShift() == 48);
			Assert::IsTrue(res2.getMinutes() == -1);
		}
	};
}