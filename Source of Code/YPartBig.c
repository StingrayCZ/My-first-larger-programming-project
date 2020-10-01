#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

int YPartBIGD(BB MOD, BB nums[])
{
	
	#ifdef PRINT
	EMPTYLINE
	printf("Start aplikace YPartBIGD");
	#endif

	BB mod;
	BB resultA, resultB, resultC;

	
	//assert(modulus && nums[]);
	
	mod = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	
	bdSetEqual(mod, MOD);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check of input values \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	#endif


	for(uint32_t  i = 0; i <= 100; i++)
	{
		
		bdSetShort(resultA, i);   // int i => BIGD
		
		bdPower(resultB, resultA, 2);
		
		bdModulo(resultC, resultB, mod);
		
		#ifdef PRINT
		EMPTYLINE
		printf("Check of computed values \n\r");
		bdPrintDecimal("resultA = ", resultA, " \n\r");
		bdPrintDecimal("resultB = ", resultB, " \n\r");
		bdPrintDecimal("resultC = ", resultC, " \n\r");
		#endif		
		
		bdSetEqual(nums[i], resultC);

	}
	
	bdFree(&mod);

	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	
	return 0;

}