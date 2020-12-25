#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.4-1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest641
{
	TEST_CLASS(UnitTest641)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t[10] = {-5, -4, 0, 10, 25, -25, 1, 4, -1, 0};

			int M = SearchMin(t, 10);
			int First = SearchFirst(t, 10);
			int Last = SearchLast(t, 10, First);
			int S = Sum(t, 3, 7);

			Sort(t, 10);

			
			Assert::AreEqual(M, -25);
			Assert::AreEqual(First, 3);
			Assert::AreEqual(Last, 7);
			Assert::AreEqual(S, 1);
			Assert::AreEqual(t[0], 0);
		}
	};
}
