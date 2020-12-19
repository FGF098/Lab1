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

		TEST_METHOD(ZeroTimeConstructorCheck)
		{
			Time temp = Time();
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(NormalConstructorTimeCheck)
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

		TEST_METHOD(NormalSetterTimeCheck)
		{
			int normalHours = 16;
			int normalMinutes = 17;
			int normalSeconds = 18;
			Time temp = Time();
			temp.setTime(normalHours, normalMinutes, normalSeconds);
			bool sameHours = temp.getHours() == normalHours;
			bool sameMinutes = temp.getMinutes() == normalMinutes;
			bool sameSeconds = temp.getSeconds() == normalSeconds;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(Invalid60ConstructorTimeCheck)
		{
			int invalidHours = 60;
			int invalidMinutes = 60;
			int invalidSeconds = 60;
			Time temp = Time(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(InvalidConstructorTimeCheck)
		{
			int invalidHours = 61;
			int invalidMinutes = 62;
			int invalidSeconds = 63;
			Time temp = Time(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(Invalid60SetterTimeCheck)
		{
			int invalidHours = 60;
			int invalidMinutes = 60;
			int invalidSeconds = 60;
			Time temp = Time();
			temp.setTime(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}

		TEST_METHOD(InvalidSetterTimeCheck)
		{
			int invalidHours = 61;
			int invalidMinutes = 62;
			int invalidSeconds = 63;
			Time temp = Time();
			temp.setTime(invalidHours, invalidMinutes, invalidSeconds);
			bool sameHours = temp.getHours() == 0;
			bool sameMinutes = temp.getMinutes() == 0;
			bool sameSeconds = temp.getSeconds() == 0;
			Assert::IsTrue(sameHours && sameMinutes && sameSeconds);
		}
	};
}
