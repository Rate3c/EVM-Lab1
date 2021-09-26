#pragma once
#include <string>
#include <sstream>
#include <iostream>
static class IOUtility
{
public:
	template <typename T>
	static std::string BinaryRepresentation(T value)		
	{
		std::stringstream result;			//not the most optimal way, but at least it is simple and understandable
		result << std::ios::bin << value;		
		return result.str;
	}

private:
};

