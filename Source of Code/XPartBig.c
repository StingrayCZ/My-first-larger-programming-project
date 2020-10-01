#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

int XPartBIGD(BB P, BB A, BB B, BB nums[])
{
		
	#ifdef PRINT
	EMPTYLINE
	printf("Start aplikace XPartBIGD");
	#endif

	BB mod, a, b;;
	BB resultA, resultB, resultC, resultD, resultE;
	BB x;    // auxiliary
	
	
	//assert(P && A && B && nums[]);
	
	mod = bdNew();
	a = bdNew();
	b = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	resultD = bdNew();
	resultE = bdNew();
	
	x = bdNew();
	
	bdSetEqual(mod, P);
	bdSetEqual(a, A);
	bdSetEqual(b, B);
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check of input values \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	bdPrintDecimal("a = ", a, " \n\r");
	bdPrintDecimal("b = ", b, " \n\r");
	#endif
	
	// Weierstrass equation y^2 = x^3 + ax + b
	
	
	//for(int64_t i = 0; i <= p; i++)   // original

	for(uint32_t i = 0; i <= 100; i++)
	{
		
		bdPower(resultA, x, 3);
		
		bdMultiply(resultB, a, x);
		
		bdAdd(resultC, resultA, resultB);
		
		bdAdd(resultD, resultC, b);
		
		bdModulo(resultE, resultD, mod);
		
		bdSetEqual(nums[i], resultE);
		
		#ifdef PRINT
		EMPTYLINE
		printf("Values of results \n\r");
		bdPrintDecimal("resultA = ", resultA, " \n\r");
		bdPrintDecimal("resultB = ", resultB, " \n\r");
		bdPrintDecimal("resultC = ", resultC, " \n\r");
		bdPrintDecimal("resultD = ", resultD, " \n\r");
		bdPrintDecimal("resultE = ", resultE, " \n\r");
		#endif
		
		bdIncrement(x);
	}
	
	bdFree(&mod);
	bdFree(&a);
	bdFree(&b);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&resultD);
	bdFree(&resultE);
	
	bdFree(&x);

	
	return 0;

}
