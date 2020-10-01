#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT


// Adopted and edited part of library https://www.di-mgt.com.au/bigdigits.html
int RandomNumber(unsigned char *bytes, size_t nbytes, const unsigned char *seed, size_t seedlen)
/* Our own (very insecure) random generator call-back function using good old rand() 
   This demonstrates the required format for BD_RANDFUNC
   -- replace this in practice with your own cryptographically-secure function.
*/
{
	unsigned int myseed;
	size_t i;
	int offset;

	/* Use time - then blend in seed, if any */
	myseed = (unsigned)time(NULL);
	if (seed)
	{
		for (offset = 0, i = 0; i < seedlen; i++, offset = (offset + 1) % sizeof(unsigned))
			myseed ^= ((unsigned int)seed[i] << (offset * 8));
	}

	//srand(myseed);
	srand(PHY_RandomReq());    //  Random number generator by LWM mesh
	while (nbytes--)
	{
		*bytes++ = rand() & 0xFF;
	}

	return 0;
}

int SecretKeyBIGD(BB OrderG, BB SecKey)
{
	BB order;
	BB resultA, resultB, resultC, resultD;
	BB auxNum;
	BB One, Two, Three, Zero;
	
	int8_t compareA, compareB, compareC;
	
	order = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	resultD = bdNew();
	
	auxNum = bdNew();
	
	One = bdNew();
	Two = bdNew();
	Three = bdNew();
	Zero = bdNew();
		
	bdSetEqual(order, OrderG);
	bdConvFromHex(auxNum, "2");
	
	bdConvFromHex(One, "1");
	bdConvFromHex(Two, "2");
	bdSetZero(Zero);
	
		
	bdRandomSeeded(resultA, 512, (const unsigned char*)"", 0, RandomNumber);  // 512 bits key
	
	bdSubtract(resultB, order, auxNum);
	
	bdModulo(resultC, resultA, resultB);   // cut-off
	
	
	compareA = bdConvFromHex(resultC, Two);
	compareB = bdConvFromHex(resultC, One);
	compareC = bdConvFromHex(resultC, Zero);
		
	
	// Uprage due to solution of PointComp algorithm (order - 2) => elimination of first point end zero-point
	if(compareA == 0)
	{
		
		bdAdd(resultD, resultC, One);   // result += 1;
		
	}
	else if(compareB == 0)
	{
		bdAdd(resultD, resultC, Two);  // result += 2;
	}
	else if(compareC == 0)
	{

		bdAdd(resultD, resultC, Three);  // result += 3;
				
	}

	bdSetEqual(SecKey, resultD);

	// FLUSH Objects
	bdFree(&order);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&resultD);
	
	bdFree(&auxNum);
	
	bdFree(&One);
	bdFree(&Two);
	bdFree(&Three);
	bdFree(&Zero);
	
	return 0;
}