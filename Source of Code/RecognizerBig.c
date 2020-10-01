#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");

int RecogniserBIGD(uint8_t *RESULT, BB Xi, BB Yi, BB Xj, BB Yj)
{
	
	BB xa, ya, xb, yb;
	BB ZERO;
	
	
	int8_t compareA, compareB, compareC, compareD;
	
	//assert(RESULT && Xi && Yi && Xj && Yj);
		
	xa = bdNew();
	ya = bdNew();
	xb = bdNew();
	yb = bdNew();
	
	ZERO = bdNew();
	
	bdSetEqual(xa, Xi);
	bdSetEqual(ya, Yi);
	bdSetEqual(xb, Xj);
	bdSetEqual(yb, Yj);
	
	
	bdConvFromHex(ZERO, "0");
	
	
	compareA = bdCompare(xa, xb);
	compareB = bdCompare(ya, yb);
	compareC = bdCompare(ya, ZERO);
	compareD = bdCompare(yb, ZERO);
		

	if(compareA == 0) // If coordiantes xa and xb are same
	{

		if(compareB == 0)  // And also ya and yb are same, will use SAME method, return 1
		{
			if(compareC  == 0)
			{
				*RESULT = 66; // bad result :(
			}

			else if(compareC == 0)
			{
				*RESULT = 66;   // bad result :(
			}

			else
			{
				*RESULT =  1;  // will use SAME method
			}

		}
		else
		{
			*RESULT =  66; // End of program. This never happend, perhaps
		}
	}

	else if(compareA != 0)
	{

		*RESULT =  2;   // will use DIFF method
	}
	
	bdFree(&xa);
	bdFree(&ya);
	bdFree(&xb);
	bdFree(&yb);
	bdFree(&ZERO);

	return 0;
}