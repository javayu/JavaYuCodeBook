#pragma once
#include<stdexcept>
using namespace std;

namespace CodeLib{
	template<typename T>
	class Stack{
	public:
		friend class StackTest;

		Stack(size_t maxSize = 500)
		{
			capacity = maxSize;
			vals = new T[capacity];
			length = 0;
		}

		~Stack(){ 
			if(vals != 0) 
				delete[] vals;
		}

		Stack & operator=(const Stack & rhs)
		{
			if( this != &rhs)
			{
				capacity = rhs.capacity;
				length =  rhs.length;
				if(vals != 0)
					delete[] vals;
				vals = new T[capacity];
				for( size_t i=0; i<length; i++)
					vals[i] = rhs.vals[i];
			}
			return *this;
		}

		T pop()
		{
			if(empty())
				throw underflow_error("Stack is empty");
			return vals[--length];
		}

		Stack & push(T val)
		{
			if(length >= capacity)
				doubleCapacity();
			vals[length++] = val;
			return *this;
		}

		inline bool empty() { return length <= 0; }

		inline void clear() { length = 0;	}

	private:
		void doubleCapacity()
		{
			capacity *= 2;
			T * newVals = new T[capacity];
			for(size_t i=0; i<length; i++)
				newVals[i] = vals[i];
			delete[] vals;
			vals = newVals;
		}

		T * vals;
		size_t capacity;
		size_t length;
	};
}
