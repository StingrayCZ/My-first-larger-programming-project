#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT

int TheFirstPointBIGD(BB MOD, BB A, BB B, BB Xfirst, BB Yfirst, BB OrderG)
{
	
	#ifdef PRINT
	EMPTYLINE
	printf("Start aplikace TheFirstPointBIGD");
	#endif
	
	//assert(MOD && A && B && Xfirst && Yfirst && OrderG);

	BB mod, a, b;
	BB resultA, resultB, resultC;
	BB orderBig, ZERO;
	BB XIterBig, YIterBig;
	BB IresA, IresB;
	BB AuxIAA;
	BB AuxIBA, AuxIBB, AuxIBC, AuxNOPE;
	BB OrdResA, OrdResB, OrdTwo, OrdOne;
	BB prefixXFirst, prefixYFirst;
	
	volatile BB poleA[100];
	volatile BB poleB[100];
	
	int8_t compareA, compareB;
	
	
	unsigned char s[100];
	uint32_t X_iter, Y_iter;
	
	mod = bdNew();
	a = bdNew();
	b = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	
	orderBig = bdNew();
	ZERO = bdNew();
	
	IresA = bdNew();
	IresB = bdNew();
	
	XIterBig = bdNew();
	YIterBig = bdNew();
	
	AuxIAA = bdNew();
	AuxIBA = bdNew();
	AuxIBB = bdNew();
	AuxIBC = bdNew();
	AuxNOPE = bdNew();
	
	OrdResA = bdNew();
	OrdResB = bdNew();
	OrdTwo = bdNew();
	OrdOne = bdNew();
	
	prefixXFirst = bdNew();
	prefixYFirst = bdNew();
	
	for(int8_t i = 0; i <= 100; i++)
	{
		poleA[i] = bdNew();
		poleB[i] = bdNew();
	}
	
	bdSetEqual(mod, MOD);
	bdSetEqual(a, A);
	bdSetEqual(b, B);
	bdSetZero(orderBig);
	
	bdConvFromHex(AuxIAA, "1");
	
	bdConvFromHex(AuxIBA, "1");
	bdConvFromHex(AuxIBB, "2");
	bdConvFromHex(AuxIBC, "1");
	
	bdConvFromHex(OrdTwo, "2");
	bdConvFromHex(OrdOne, "1");
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check of input values \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	bdPrintDecimal("a = ", a, " \n\r");
	bdPrintDecimal("b = ", b, " \n\r");
	bdPrintDecimal("orderBig = ", orderBig, " \n\r");
	#endif
		
	// Application XPart
	XPartBIGD(mod, a, b, poleA);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check XPartBIGD Output: \n\r");
	bdPrintDecimal("PoleA[0] = ", poleA[0], " \n\r");
	bdPrintDecimal("PoleA[1] = ", poleA[1], " \n\r");
	bdPrintDecimal("PoleA[2] = ", poleA[2], " \n\r");
	printf("And so on... \n\r");
	EMPTYLINE
	#endif
	
	
	// Application YPart
	YPartBIGD(mod, poleB);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check YPartBIGD Output: \n\r");
	bdPrintDecimal("PoleB[0] = ", poleB[0], " \n\r");
	bdPrintDecimal("PoleB[1] = ", poleB[1], " \n\r");
	bdPrintDecimal("PoleB[2] = ", poleB[2], " \n\r");
	printf("And so on... \n\r");
	EMPTYLINE
	#endif


	// Iterations X
	bdSubtract(XIterBig, mod, AuxIAA);   // mod - 1
	// Convert to uint32_t
	bdConvToDecimal(XIterBig, s, sizeof(s));
	X_iter = atoi(s);
	

	// Iterations X
	bdSubtract(IresA, mod, AuxIBA);    // mod - 1
	bdDivide(IresB, AuxNOPE, IresA, AuxIBB);    // (mod - 1)/2
	bdAdd(YIterBig, IresB, AuxIBC);    // (mod - 1)/2 + 1
	// Convert to uint32_t
	bdConvToDecimal(YIterBig, s, sizeof(s));
	Y_iter = atoi(s);
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check before atoi result(BIGD): \n\r");
	bdPrintDecimal("XIterBig = ", XIterBig, " \n\r");
	bdPrintDecimal("YIterBig = ", YIterBig, " \n\r");
	EMPTYLINE
	#endif
		
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check atoi result: \n\r");
	printf("X_iter = %d \n\r", X_iter);
	printf("Y_iter = %d \n\r", Y_iter);
	EMPTYLINE
	#endif
		
	
	
	for(uint32_t  k = 0; k <= X_iter; k++)  // Give X's
	{
		
		for(uint32_t  i = 0; i <= Y_iter; i++)  // Give Y's
		{
			compareA = bdCompare(poleA[k], poleB[i]);
			
			
			if (compareA == 0)
			{
				compareB = bdCompare(orderBig, ZERO);
				
				if(compareB == 0)
				{
					#ifdef PRINT
					EMPTYLINE
					bdPrintDecimal("X first k = ", poleA[k], " \n\r");
					bdPrintDecimal("Y first i = ", poleA[i], " \n\r");
					
					printf("print XFirst = %d \n\r", k);
					printf("print XFirst = %d \n\r", i);
					EMPTYLINE
					#endif
					
					bdSetShort(prefixXFirst, k);
					bdSetShort(prefixYFirst, i);
					
					bdSetEqual(Xfirst, prefixXFirst);
					bdSetEqual(Yfirst, prefixYFirst);
					
					#ifdef PRINT
					EMPTYLINE
					printf("print XFirst = %d \n\r", k);
					printf("print XFirst = %d \n\r", i);
					
					bdPrintDecimal("X prefix first k = ", prefixXFirst, " \n\r");
					bdPrintDecimal("Y prefix first i = ", prefixYFirst, " \n\r");
					EMPTYLINE
					#endif
					
				
				}
				
				bdIncrement(orderBig);
				#ifdef PRINT
				EMPTYLINE
				bdPrintDecimal("OrderBig = ", orderBig, " \n\r");
				EMPTYLINE
				#endif

			}
		}

	}
	
	bdMultiply(OrdResA, orderBig, OrdTwo);           // Order * 2 (include mirrored points)
	
	bdAdd(OrdResB, OrdResA, OrdOne);               // (Order * 2) + 1 (include zero point)
	
	bdSetEqual(OrderG, OrdResB);                   // send result to the next process
	
	#ifdef PRINT
	EMPTYLINE
	bdPrintDecimal("OrdResA = ", OrdResA, " \n\r");
	bdPrintDecimal("OrdResB = ", OrdResB, " \n\r");
	EMPTYLINE
	#endif
	
	// FLUSH MEMORY
	bdFree(&mod);
	bdFree(&a);
	bdFree(&b);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	
	bdFree(&orderBig);
	bdFree(&ZERO);
	
	bdFree(&IresA);
	bdFree(&IresB);
	
	bdFree(&XIterBig);
	bdFree(&YIterBig);
	
	bdFree(&AuxIAA);
	bdFree(&AuxIBA);
	bdFree(&AuxIBA);
	bdFree(&AuxIBC);
	bdFree(&AuxNOPE);
	
	bdFree(&OrdResA);
	bdFree(&OrdResB);
	bdFree(&OrdTwo);
	bdFree(&OrdOne);
	
	bdFree(&prefixXFirst);
	bdFree(&prefixYFirst);
	
	for(int8_t i = 0; i <= 100; i++)
	{
		bdFree(&poleA[i]);
		bdFree(&poleB[i]);
	}
	
	return 0;
}