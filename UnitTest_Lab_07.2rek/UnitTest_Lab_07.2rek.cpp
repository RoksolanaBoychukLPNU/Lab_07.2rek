#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2rek/Lab_07.2rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest722
{
    TEST_CLASS(UnitTest722)
    {
    public:
        TEST_METHOD(TestMaxInRow)
        {
            int r0[4] = { -5, 12, 3, 7 };
            int* a[1] = { r0 };
            Assert::AreEqual(12, MaxInRow(a, 0, 4, 1, a[0][0]));
        }

        TEST_METHOD(TestSumRowMax)
        {
            int r0[3] = { -5, 12, 3 };
            int r1[3] = { -9, -2, -4 };
            int r2[3] = { 0, 8, 8 };
            int* a[3] = { r0, r1, r2 };
            Assert::AreEqual(18, SumRowMax(a, 3, 3, 0));   // 12 + (-2) + 8
        }
    };
}
