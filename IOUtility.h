#pragma once
#include <string>
#include <sstream>
#include <iostream>
class IOUtility
{
public:
	template <typename T>
	static std::string BinaryRepresentation(T value)		
	{
		std::string result;			
		result.resize(sizeof(T) * 8);
		int sizeDeltaBits = (sizeof(long long) - sizeof(T))*8;
		
		long long valueAsBitShiftable = *(reinterpret_cast<long long*>(&value));
		
		for (int i= sizeof(T) * 8-1; i>=0; i--)
		{
			result[i] = 
				(((valueAsBitShiftable >> (1)) << (1)) ^ valueAsBitShiftable) ?			//xoring value with its copy, but with last bit nullified. we get 1(true) in case it was 1, or 0(false) in case it was 0
				'1' : '0';
			valueAsBitShiftable >>= 1;
		}

		return result;
	}
private:
};

