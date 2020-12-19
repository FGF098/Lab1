#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab1/Time.h"
// fixes error LNK 2019 (based on StackOverflow answer)
#include "../Lab1/Time.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDateTimeLab1
{
	TEST_CLASS(UnitTestTime)
	{
	public:

		TEST_METHOD(DefaultConstructorCheck)
		{
			Time temp = Time();
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(NormalConstructorCheck)
		{
			int normalHours = 13;
			int normalMinutes = 14;
			int normalSeconds = 15;
			Time temp = Time(normalHours, normalMinutes, normalSeconds);
			bool sameHours = temp.getHours() == normalHours;
			bool sameMinutes = temp.getMinutes() == normalMinutes;
			bool sameSeconds = temp.getSeconds() == normalSeconds;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(NormalSetterCheck)
		{
			int normalHours = 16;
			int normalMinutes = 17;
			int normalSeconds = 18;
			Time temp = Time();
			bool valid = temp.setTime(normalHours, normalMinutes, normalSeconds);
			bool sameHours = temp.getHours() == normalHours;
			bool sameMinutes = temp.getMinutes() == normalMinutes;
			bool sameSeconds = temp.getSeconds() == normalSeconds;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds && valid);
		}

		TEST_METHOD(Invalid60ConstructorCheck)
		{
			int invalidHours = MINUTES_AND_SECONDS;
			int invalidMinutes = MINUTES_AND_SECONDS;
			int invalidSeconds = MINUTES_AND_SECONDS;
			Time temp = Time(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(InvalidConstructorCheck)
		{
			int invalidHours = MINUTES_AND_SECONDS + 1;
			int invalidMinutes = MINUTES_AND_SECONDS + 2;
			int invalidSeconds = MINUTES_AND_SECONDS + 3;
			Time temp = Time(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(Invalid60SetterCheck)
		{
			int invalidHours = MINUTES_AND_SECONDS;
			int invalidMinutes = MINUTES_AND_SECONDS;
			int invalidSeconds = MINUTES_AND_SECONDS;
			Time temp = Time();
			bool valid = temp.setTime(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds && !valid);
		}

		TEST_METHOD(InvalidSetterCheck)
		{
			int invalidHours = MINUTES_AND_SECONDS + 4;
			int invalidMinutes = MINUTES_AND_SECONDS + 5;
			int invalidSeconds = MINUTES_AND_SECONDS + 6;
			Time temp = Time();
			bool valid = temp.setTime(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds && !valid);
		}
	};
}
