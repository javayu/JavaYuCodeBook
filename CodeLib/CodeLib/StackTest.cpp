#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CodeLib
{		
	TEST_CLASS(StackTest)
	{
	public:
		Stack<int> a;

		TEST_METHOD_INITIALIZE(StackInitiate)
		{
			a = Stack<int>(10);
		}
		
		TEST_METHOD(StackPushPop)
		{
			int tmp = 1;
			Assert::IsTrue(a.push(tmp).pop() == tmp);
		}
		
		TEST_METHOD(StackEmpty)
		{
			Assert::IsTrue(a.empty());
			a.push(1);
			Assert::IsFalse(a.empty());
			a.pop();
			Assert::IsTrue(a.empty());
		}

		TEST_METHOD(StackClear)
		{
			for( int i =0; i<5; i++)
				a.push(i);
			a.clear();
			Assert::IsTrue(a.empty());
		}	
		
		TEST_METHOD(StackResize)
		{
			for( int i=0; i<15; i++)
				a.push(i);
			Assert::AreEqual((int)a.capacity, 20);
			a.clear();
		}

		TEST_METHOD(StackPopAll)
		{
			for( int i=0; i<15; i++)
				a.push(i);
			int len = a.length;
			while(!a.empty() && len>0 )
			{
				a.pop();
				len--;
			}
			Assert::IsTrue(a.empty() && len == 0);
		}
		
		TEST_METHOD_CLEANUP(StackDestruct)
		{
		}
	};
}