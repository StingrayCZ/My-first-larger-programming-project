#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

int XDiffBIGD(BB RESULT, BB MOD, BB Lambda, BB Xi, BB Xj)
{
	#ifdef PRINT
	EMPTYLINE
	printf("Start aplikace XDiffBIGD");
	#endif

	BB mod, lambda, xi, xj;
	BB resultA, resultB, resultC, resultD, resultE;    // auxiliary
	
	//assert(RESULT && MOD && Lambda && Xi && Xj);
	
	int8_t compare;
	
	mod = bdNew();
	lambda = bdNew();
	xi = bdNew();
	xj = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	resultD = bdNew();
	resultE = bdNew();
	
	bdSetEqual(mod, MOD);
	bdSetEqual(lambda, Lambda);
	bdSetEqual(xi, Xi);
	bdSetEqual(xj, Xj);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Test prenesenych hdonot \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	bdPrintDecimal("lambda = ", lambda, " \n\r");
	bdPrintDecimal("xi = ", xi, " \n\r");
	bdPrintDecimal("xj = ", xj, " \n\r");
	#endif
	
	bdSquare(resultA, lambda);
	
	#ifdef PRINT
	EMPTYLINE
	bdPrintDecimal("lambda^2 = ", resultA, " \n\r");
	#endif
	
	compare = bdCompare(resultA, xi);
	
	#ifdef PRINT
	EMPTYLINE
	printf("CompareA = %d \n\r", compare);
	#endif
	
	if(compare == 1){
		
		#ifdef PRINT
		EMPTYLINE
		printf("Aktivace CompareA -1 \n\r");
		#endif
		
		bdSubtract(resultB, resultA, xi);
		
		
		compare = bdCompare(resultB, xj);
		
		if(compare == 1){
			
			#ifdef PRINT
			EMPTYLINE
			printf("Aktivace CompareB 1 \n\r");
			#endif
						
			bdSubtract(resultC, resultB, xj);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Value before modulo = ", resultC, " \n\r");
			#endif
			
			bdModulo(resultE, resultC, mod);
					
			}
		
		else if(compare == (-1)){
			
			#ifdef PRINT
			EMPTYLINE
			printf("Aktivace CompareB -1 \n\r");
			#endif
			
			bdSubtract(resultC, xj, resultB);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Value before modulo = ", resultC, " \n\r");
			#endif
			
			bdModulo(resultD, resultC, mod);
			
			bdSubtract(resultE, mod, resultD);
			
		}
				
	}
	
	else if(compare == (-1)){
		
		#ifdef PRINT
		EMPTYLINE
		printf("Aktivace CompareA -1 \n\r");
		#endif
		
		bdSubtract(resultB, xi, resultA);
		
		bdAdd(resultC, resultB, xj);
		
		#ifdef PRINT
		EMPTYLINE
		bdPrintDecimal("Value before modulo = ", resultC, " \n\r");
		#endif
		
		bdModulo(resultD, resultC, mod);
		
		bdSubtract(resultE, mod, resultD);
		
		}
		
	else if(compare == 0){
		
		#ifdef PRINT
		EMPTYLINE
		printf("Aktivace CompareA 0 \n\r");
		#endif
		
		bdModulo(resultD, xj, mod);
		
		bdSubtract(resultE, mod, resultD);
	}
	
	bdSetEqual(RESULT, resultE);

	
	bdFree(&mod);
	bdFree(&lambda);
	bdFree(&xi);
	bdFree(&xj);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&resultD);
	bdFree(&resultE);

	return 0;
}