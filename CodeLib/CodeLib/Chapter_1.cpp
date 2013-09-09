#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
// Reverse a null-terminated string
/*
* Reverse a null-terminated string
*/

void reverse(char * str)
{
	char * beg = str;
	char * end = str;
	for(; *end != NULL; end++);
    end--;
	char tmp;
	while(beg < end)
	{
		char tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++;
		end--;
	}
}


namespace CodeLib
{		
	TEST_CLASS(Chap1Test)
	{
	public:

		TEST_METHOD_INITIALIZE(C1Initiate)
		{
		}
		
		TEST_METHOD(Q_1_2_Reverse)
		{
			char * a = new char[10];
			for(char c = 'a'; c < 'g'; c++)
				a[c-'a'] = c;
			a[6] = NULL;
			reverse(a);
			char b[] = "fedcba";
			for(int i = 0; a[i] != NULL; i++)
				Assert::IsTrue(a[i] == b[i]);
		}
		
		TEST_METHOD_CLEANUP(C1Clean)
		{
		}
	};
}