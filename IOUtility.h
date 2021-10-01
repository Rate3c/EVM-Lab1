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
		std::string result;			//not the most optimal way, but at least it is simple and understandable
		result.resize(sizeof(T) * 8);

		
		for (int i= sizeof(T) * 8-1; i>=0; i--)
		{
			result[i] = 
				(((value >> 1) << 1) ^ value) ?			//xoring value with its copy, but with last bit nullified. we get 1(true) in case it was 1, or 0(false) in case it was 0
				'1' : '0';
			value >>= 1;
		}

		return result;
	}

private:
};

