#pragma once
#include <string>
class IOUtility
{
public:
	template <typename T>
	//lets not do koldunstvo with inlines and define this thing right here
	static std::string BinaryRepresentation(T value)		
	{
		//remember about sizeof()
	}

	static void ClearCin();		//removes all input remnants from std::cin
private:
};

