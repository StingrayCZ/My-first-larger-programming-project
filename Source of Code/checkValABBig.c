#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT


void checkValABBIGD(uint8_t *TESTvalue, BB MOD, BB A, BB B)
{
	
	#ifdef PRINT
	printf("Start aplikace checkValABBIGD...\n\r");
	#endif
	
	
	BB mod, a, b;
	BB resultA, resultB, resultC, resultD, resultE, resultF;
	BB AuxNumA, AuxNumB, AuxNumC;
	
	int8_t compareA, compareB, compareC;
	
	//assert(TESTvalue && mod && A && B);
	
	mod = bdNew();
	a = bdNew();
	b = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	resultD = bdNew();
	resultE = bdNew();
	resultF = bdNew();
	
	AuxNumA = bdNew();
	AuxNumB = bdNew();
	AuxNumC = bdNew();
	
	bdSetEqual(mod, MOD);
	bdSetEqual(a, A);
	bdSetEqual(b, B);
	
	bdConvFromHex(AuxNumA, "4");   // 4
	bdConvFromHex(AuxNumB, "1b");  // 27
	bdSetZero(AuxNumC);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Kontrola vstupu: \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	bdPrintDecimal("a = ", a, " \n\r");
	bdPrintDecimal("b = ", b, " \n\r");
	#endif
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check of auxiliary values: \n\r");
	bdPrintDecimal("AuxNumA = ", AuxNumA, " \n\r");
	bdPrintDecimal("AuxNumB = ", AuxNumB, " \n\r");
	bdPrintDecimal("AuxNumC = ", AuxNumC, " \n\r");
	#endif
	
	
	compareA = bdCompare(a, mod);
	
	compareB = bdCompare(b, mod);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Comparsion tests: \n\r");
	printf("ComparsionA = %d \n\r", compareA);
	printf("ComparsionB = %d \n\r", compareB);
	#endif
	

	if(compareA == 0)     // a == mod
	{

		*TESTvalue = 2;
	}

	else if(compareB == 0)    // b == MOD
	{

		*TESTvalue = 2;
	}

	else
	{
		
		bdPower(resultA, a, 3); // a^3
		bdMultiply(resultB, AuxNumA,  resultA);  // 4 * a^3
		
		bdPower(resultC, b, 2); // b^2
		bdMultiply(resultD, AuxNumB, resultC);  // 27 * b^2
		
		bdAdd(resultE, resultB, resultD);        // 4 * a^3 + 27 * a^3
		
		bdModulo(resultF, resultE, mod);       // (4 * a^3 + 27 * a^3) mod p
		
		
		#ifdef PRINT
		EMPTYLINE
		printf("Check result of computations: \n\r");
		bdPrintDecimal("resultA = ", resultA, " \n\r");
		bdPrintDecimal("resultB = ", resultB, " \n\r");
		bdPrintDecimal("resultC = ", resultC, " \n\r");
		bdPrintDecimal("resultD = ", resultD, " \n\r");
		bdPrintDecimal("resultE = ", resultE, " \n\r");
		bdPrintDecimal("resultF = ", resultF, " \n\r");
		#endif
		
		
		compareC = bdCompare(resultF, AuxNumC);
		
		
		#ifdef PRINT
		EMPTYLINE
		printf("Compare between result and 0 => %d \n\r", compareC);
		#endif
		
		
		if (compareC != 0)
		{
			*TESTvalue = 1;      // approval value
			
		}
		else
		{
			*TESTvalue = 2;      // refusal value
		}

	}
	
	
	bdFree(&mod);
	bdFree(&a);
	bdFree(&b);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&resultD);
	bdFree(&resultE);
	bdFree(&resultF);
	
	bdFree(&AuxNumA);
	bdFree(&AuxNumB);
	bdFree(&AuxNumC);

	return 0;
	
	
}