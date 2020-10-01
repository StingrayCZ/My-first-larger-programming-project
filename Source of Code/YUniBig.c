#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT


int YUniBIGD(BB RESULT, BB MOD, BB Lambda, BB X, BB Y, BB X_k)
{
	
	#ifdef PRINT
	printf("Start aplikace YUniBIGD...\n\r");
	#endif
	
		
	//assert(RESULT && MOD && Lambda && X && Y && X_k);
	
	int compareA, compareB;
	
	BB mod, lambda, x, x_k, y;
	BB resultA, resultB, resultC, resultD, resultE;
	
	mod = bdNew();
	lambda= bdNew();
	x = bdNew();
	y = bdNew();
	x_k = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	resultD = bdNew();
	resultE = bdNew();
	
	
	bdSetEqual(mod, MOD);
	bdSetEqual(lambda, Lambda);
	bdSetEqual(x, X);
	bdSetEqual(y, Y);
	bdSetEqual(x_k, X_k);
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Kontrola vstupu: \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	bdPrintDecimal("lambda = ", lambda, " \n\r");
	bdPrintDecimal("x = ", x, " \n\r");
	bdPrintDecimal("y = ", y, " \n\r");
	bdPrintDecimal("x_k = ", x_k, " \n\r");
	#endif
	
	
	compareA = bdCompare(x, x_k);
	
	#ifdef PRINT
		EMPTYLINE
		printf("compare %d \n\r", compareA);
		#endif
	
	if(compareA == 1){
		
		#ifdef PRINT
		EMPTYLINE
		printf("Aktivace CompareA 1");
		#endif
		
		bdSubtract(resultA, x, x_k);
		bdMultiply(resultB, lambda, resultA);
		
		compareB = bdCompare(resultB, y);
		
		if(compareB == 1){
			
			#ifdef PRINT
			EMPTYLINE
			printf("Aktivace CompareB 1 \n\r");
			#endif
			
			bdSubtract(resultC, resultB, y);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Value before modulo = ", resultC, " \n\r");
			#endif
			
			bdModulo(resultE, resultC, mod);
		}
		else if(compareB == (-1)){
			
			#ifdef PRINT
			EMPTYLINE
			printf("Aktivace CompareB -1 \n\r");
			#endif
			
			bdSubtract(resultC, y, resultB);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Value before modulo = ", resultC, " \n\r");
			#endif
			
			bdModulo(resultD, resultC, mod);
			bdSubtract(resultE, mod, resultD);
		}
	}
	else if(compareA == (-1)){
		
		#ifdef PRINT
		EMPTYLINE
		printf("Aktivace CompareA -1 \n\r");
		#endif
		
		bdSubtract(resultA, x_k, x);
		bdMultiply(resultB, lambda, resultA);	
		bdAdd(resultC, resultB, y);
		
		#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Value before modulo = ", resultC, " \n\r");
			#endif
		
		bdModulo(resultD, resultC, mod);
		bdSubtract(resultE, mod, resultD);
		
	}
	
	else if(compareA == 0){
		
		#ifdef PRINT
		EMPTYLINE
		printf("Aktivace CompareA 0 \n\r");
		#endif
		
		bdModulo(resultD, y, mod);
		bdSubtract(resultE, mod, resultD);
	}
	
	
		bdSetEqual(RESULT, resultE);  
		
		
	bdFree(&mod);
	bdFree(&lambda);
	bdFree(&x);
	bdFree(&x_k);

	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&resultD);
	bdFree(&resultE);
	
	
	return 0;

}