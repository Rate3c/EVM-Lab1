#pragma once
static class BitSwapper
{
public:
	
	template <typename T>
	//lets not do koldunstvo with inlines and define this thing right here
	static T SwapNPairsStartingFromBitIndex(T value, int nPairs, int firstBitIndex)
	{
		
	}

	

private:
	template <typename T>
	static bool _XorOnPairNBitsAway(T value, int margin)
	{
		//spaghetti time!

		//first we shift value right in way that the last bit is the first bit of our pair 
		// then we shift it back sizeof(T)-1 blocks back. The first bit in resulting block is the first bit of pair now (all other bits are set to 0)
		// then we do the same, but for the second bit of pair
		// then... we use binary Xor! If bit1==bit2, the result will be nothing but zero, and this thing will return false
		
		// I havent tested it tho

		int sizeOfTBits = sizeof(T) * 8;

		return ((value >> (sizeOfTBits - (margin + 1)) << sizeOfTBits - 1) ^
			    (value >> (sizeOfTBits - (margin + 2)) << sizeOfTBits - 1);
	}
};

