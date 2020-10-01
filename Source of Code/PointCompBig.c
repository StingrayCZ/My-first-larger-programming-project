#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

int PointCompBIGD(BB X, BB Y, BB a_asymptote, BB modulus, BB ResultX, BB ResultY, uint32_t *iteration, uint8_t *STOPval)
{
	#ifdef PRINT
	printf("Start aplikace PointCompBIG...\n\r");
	#endif
	
	
	BB Xi, Yi, Xj, Yj;
	BB mod, a, lambda;
	
	BB resultBigA, resultBigB, resultBigC;
	
	uint32_t repeat;
	uint8_t result; 
	
	assert(X && Y && a_asymptote && modulus && ResultX && ResultY);
	
	Xi = bdNew();
	Yi = bdNew();
	Xj = bdNew();
	Yj = bdNew();
	
	mod = bdNew();
	a = bdNew();
	lambda = bdNew();	
	
		
	resultBigA = bdNew();	
	resultBigB = bdNew();
	resultBigC = bdNew();
	
	
	bdSetEqual(Xi, X);
	bdSetEqual(Yi, Y);
	
	bdSetEqual(Xj, Xi);
	bdSetEqual(Yj, Yi);
	
	bdSetEqual(a, a_asymptote);
	bdSetEqual(mod, modulus);
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Kontrola vstupu: \n\r");
	bdPrintDecimal("Xi = ", Xi, " \n\r");
	bdPrintDecimal("Yi = ", Yi, " \n\r");
	bdPrintDecimal("Xj = ", Xj, " \n\r");
	bdPrintDecimal("Yj = ", Yj, " \n\r");
	bdPrintDecimal("Asymptota a = ", a, " \n\r");
	bdPrintDecimal("Modulus mod = ", mod, " \n\r");
	#endif
	
	
	// Value for number of iteration
	repeat = *iteration;	
	
	#ifdef PRINT
	printf("Pocet opakovani %d \n\r", repeat);
	#endif
	
	
	EMPTYLINE

	for(uint32_t i = 1; i <= (repeat - 2); i++)
	{
		RecogniserBIGD(&result, Xi, Yi, Xj, Yj);
		
		#ifdef PRINT
		EMPTYLINE
		printf("Zvolena metoda (cislo) %d \n\r", result);
		#endif

		if(result == 1)
		{
			#ifdef PRINT
			printf("Metoda SAME \n\r");
			#endif
			
			LamdaSameBIGD(resultBigA, mod, Xi, Yi, a);
			
			XSameBIGD(resultBigB, mod, resultBigA, Xi);
			
			YUniBIGD(resultBigC, mod, resultBigA, Xi, Yi, resultBigB);
			
			#ifdef PRINT
			printf("Iterace = %d \n\r", i);
			bdPrintDecimal("LambdaSame = ", resultBigA, " \n\r");
			bdPrintDecimal("XSame = ", resultBigB, " \n\r");
			bdPrintDecimal("YSame = ", resultBigC, " \n\r");
			EMPTYLINE
			#endif
						
			*STOPval = 1;
			

		}

		else if(result == 2)
		{
			#ifdef PRINT
			printf("Metoda DIFF \n\r");
			#endif
			
			LamdaDiffBIGD(resultBigA, mod, Xi, Yi, Xj, Yj);
			

			XDiffBIGD(resultBigB, mod, resultBigA, Xi, Xj);
			
			YUniBIGD(resultBigC, mod, resultBigA, Xi, Yi, resultBigB);
			
			#ifdef PRINT
			printf("Iterace = %d /n/r", i);
			bdPrintDecimal("LambdaDiff = ", resultBigA, " \n\r");
			bdPrintDecimal("XDiff = ", resultBigB, " \n\r");
			bdPrintDecimal("YDiff = ", resultBigC, " \n\r");
			EMPTYLINE
			#endif

			*STOPval = 1;
			

		}

		else if(result == 66)
		{
			
			*STOPval = 66;
		}
				
		bdSetEqual(Xj, resultBigB);	
		bdSetEqual(Yj, resultBigC);	

	}
	


	bdSetEqual(ResultX, resultBigB);	
	bdSetEqual(ResultY, resultBigC);	
	
	
	bdFree(&Xi);
	bdFree(&Yi);
	bdFree(&Xj);
	bdFree(&Yj);
	
	bdFree(&mod);
	bdFree(&a);
	bdFree(&lambda);
	
	bdFree(&resultBigA);
	bdFree(&resultBigB);
	bdFree(&resultBigC);
	
		
}