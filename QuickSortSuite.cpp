#include "pch.h"
#include "CppUnitTest.h"
#include "../QuickSort/QuickSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuickSortSuite
{
	TEST_CLASS(QuickSortSuite)
	{
	public:
		
		TEST_METHOD(TestQuickSort1)
		{
			int counttrue = 0;
			int expected[] = {-5, -3, 0, 3, 4};
			int actual[] = {0, 3, -1, 4, -5};
			Sort S(actual, 5);
			S.quicksort(0, 4);
			for (int i = 0; i < 5; i++) {
				if (expected[i] == actual[i]) {
					counttrue += 1;
				}
			}
			if (counttrue == 5) {
				Logger::WriteMessage("Successful Quick Sort");
			}
		}
		TEST_METHOD(TestQuickSort2)
		{
			int counttrue = 0;
			int expected[] = {-5, -5, 0, 3, 4, 5, 6};
			int actual[] = {0, 3, 5, -5, 6, 4, -5};
			Sort S(actual, 7);
			S.quicksort(0, 6); 
			for (int i = 0; i < 7; i++) {
				if (expected[i] == actual[i]) {
					counttrue += 1;
				}
			}
			if (counttrue == 7) {
				Logger::WriteMessage("Successful Quick Sort");
			}
		}
		TEST_METHOD(TestQuickSort3)
		{
			int counttrue = 0;
			int expected[] = {-1, -1, -1, -1, -1, -1};
			int actual[] = {-1, -1, -1, -1, -1, -1};
			Sort S(actual, 6);
			S.quicksort(0, 5);
			for (int i = 0; i < 6; i++) {
				if (expected[i] == actual[i]) {
					counttrue += 1;
				}
			}
			if (counttrue == 6) {
				Logger::WriteMessage("Successful Quick Sort");
			}
		}
		TEST_METHOD(TestQuickSort4)
		{
			int counttrue = 0;
			int expected[] = {-50, -49, -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, 
							  -38, -37, -36, -35, -34, -33, -32, -31, -30, -29, -28, -27, 
							  -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, 
							  -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 
							   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
							   18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
				               33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49
							 };
			int actual[] = {-7, 27, 47, 20, 19, 40, -48, -40, 36, -32, 18, -8, 13, -33, 9, 
							-1, -28, -29, -31, 2, -24, -41, 6, 12, -50, 1, -44, 33, 10, -43, 
							25, -45, -6, 39, 8, 7, -38, 48, -36, 49, 29, -21, -2, 0, 5, 3, 
							21, 30, 16, 17, -46, 15, -42, 38, -25, -26, -15, 4, 44, -49, -30, 
							-35, -22, -19, -20, 46, 32, 11, 45, 42, -4, -12, -27, 28, 43, 34, 
							-16, 41, -37, -3, 37, 14, -13, 22, 31, 24, -47, -34, -39, 23, -10, 
							26, -14, -17, -11, -18, -9, -23, 35, -5
							};
			Sort S(actual, 100);
			S.quicksort(0, 99);
			for (int i = 0; i < 100; i++) {
				if (expected[i] == actual[i]) {
					counttrue += 1;
				}
			}
			if (counttrue == 100) {
				Logger::WriteMessage("Successful Quick Sort");
			}
		}
		TEST_METHOD(TestQuickSort5)
		{
			int* arr = new int[0];
			try
			{
				Sort S(arr, 0);
				S.quicksort(0, -1);
			}
			catch (const std::exception& p1)
			{
				Logger::WriteMessage(p1.what());
			}
			delete[] arr;
		}
		TEST_METHOD(TestQuickSort6)
		{
			int* arr = NULL;
			try
			{
				Sort S(arr, 0);
				S.quicksort(0, -1);
			}
			catch (const std::exception& p1)
			{
				Logger::WriteMessage(p1.what());
			}
			delete[] arr;
		}
	};
}
