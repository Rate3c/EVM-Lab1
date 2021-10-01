#pragma once
#include <stdexcept>
#include <iostream>
#include "IOUtility.h"
class BitSwapper
{
public:
	
	template <typename T>
	//lets not do koldunstvo with inlines and define this thing right here
	static T SwapNPairsStartingFromBitIndex(const T& value, int nPairs, int firstBitIndex)
	{
		
		switch (sizeof(T))				//chosing typename with same size as T
										
		{
		case 1:
			return DoBitSwapWithInt<T,__int8>(value, nPairs, firstBitIndex);
		case 2:
			return DoBitSwapWithInt<T, __int16>(value, nPairs, firstBitIndex);
		case 4:
			return DoBitSwapWithInt<T, __int32>(value, nPairs, firstBitIndex);
		case 8:
			return DoBitSwapWithInt<T, __int64>(value, nPairs, firstBitIndex);
		default:
			throw std::invalid_argument("hehe funny ex go brrr");
		}
	}

private:
	template <
		typename T1,			//typename of value to be processed
		typename T2				//bit shiftable typename with size same as T1
	>					
	static T1 DoBitSwapWithInt(T1 value, int nPairs, int firstBitIndex)	
	{
		if (sizeof(T1) != sizeof(T2))
			throw std::invalid_argument("size of T1 != size of T2");

		T2* valAsBitShiftable = reinterpret_cast<T2*>(&value);
		
		T2 bitSwapSeq = XorSwapBitSequence(*valAsBitShiftable, nPairs, firstBitIndex);
		
		T2 result = bitSwapSeq ^ *valAsBitShiftable;
		T1* resAsT1 = reinterpret_cast<T1*>(&result);
		return *resAsT1;
	}


	template <typename T>
	static T XorSwapBitSequence(const T& value, int nPairs, int firstBitIndex)
	{
		T res = 0;
		for (int i = 0; i < nPairs; i++)
		{
			res <<= 2;
			if (BitsInPairNBitsAwayAreDifferent(value, firstBitIndex + i * 2))
				res = res | 0b11;

			//else res | 0b00. meaningless line.
		}
		
		res <<= (sizeof(T)*8 - (firstBitIndex + nPairs * 2));

		return res;
	}
	template <typename T>
	static bool BitsInPairNBitsAwayAreDifferent(const T& value, int margin)
	{
		//spaghetti time!

		//first we shift value right in way that the last bit is the first bit of our pair 
		// then we shift it back sizeof(T)-1 blocks back. The first bit in resulting block is the first bit of pair now (all other bits are set to 0)
		// then we do the same, but for the second bit of pair
		// then... we use binary Xor! If bit1==bit2, the result will be nothing but zero, and this thing will return false

		int sizeOfTBits = sizeof(T) * 8;

		return  ((value >> (sizeOfTBits - (margin + 2))) << (sizeOfTBits - 1)) ^
			    ((value >> (sizeOfTBits - (margin + 1))) << (sizeOfTBits - 1));
	}
};

