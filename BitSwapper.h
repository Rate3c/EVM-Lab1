#pragma once
class BitSwapper
{
public:
	
	template <typename T>
	//lets not do koldunstvo with inlines and define this thing right here
	static T SwapNPairsStartingFromBitIndex(T value, int nPairs, int firstBitIndex)
	{
		//use sizeof(value)
		//non-primitive T isnt a problem of this method
	}

private:
	
};

