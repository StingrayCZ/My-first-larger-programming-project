#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT

int VerifyOfPointBIGD(uint8_t *RESULT, BB modulus, BB X, BB Y, BB a, BB b){
	
	#ifdef PRINT
	printf("Start aplikace VerifyOfPointBIGD...\n\r");
	#endif
	
	//assert(modulus && X && Y && a && b);
	
	BB mod, x, y, a_pam, b_pam;
	BB resultYA, resultYB, resultXA, resultXB, resultXC, resultXD, resultXE;
	
	int8_t compare;
	
	mod = bdNew();
	x = bdNew();
	y = bdNew();
	a_pam = bdNew();
	b_pam = bdNew();
	

	resultYA = bdNew();
	resultYB = bdNew();
	
	resultXA = bdNew();
	resultXB = bdNew();
	resultXC = bdNew();
	resultXD = bdNew();
	resultXE = bdNew();
	
	bdSetEqual(mod, modulus);
	bdSetEqual(x, X);
	bdSetEqual(y, Y);
	bdSetEqual(a_pam, a);
	bdSetEqual(b_pam, b);
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Kontrola vstupu: \n\r");
	bdPrintDecimal("mod = ", mod, " \n\r");
	bdPrintDecimal("x = ", x, " \n\r");
	bdPrintDecimal("y = ", y, " \n\r");
	bdPrintDecimal("a_pam = ", a_pam, " \n\r");
	bdPrintDecimal("b_pam = ", b_pam, " \n\r");
	#endif
	
	// Y Part
	
	bdPower(resultYA, y, 2);
	bdModulo(resultYB, resultYA, mod);
	
	#ifdef PRINT
	EMPTYLINE
	bdPrintDecimal("resultYA = ", resultYA, " \n\r");
	bdPrintDecimal("resultYB = ", resultYB, " \n\r");
	#endif
	
	// X Part
	
	bdPower(resultXA, x, 3);
	
	bdMultiply(resultXB, a_pam, x);
	
	bdAdd(resultXC, resultXA, resultXB);
	
	bdAdd(resultXD, resultXC, b_pam);
	
	bdModulo(resultXE, resultXD, mod);
	
		
	#ifdef PRINT
	EMPTYLINE
	bdPrintDecimal("resultXA = ", resultXA, " \n\r");  // X^3
	bdPrintDecimal("resultXB = ", resultXB, " \n\r");  // a*x
	bdPrintDecimal("resultXC = ", resultXC, " \n\r");
	bdPrintDecimal("resultXD = ", resultXD, " \n\r");
	bdPrintDecimal("resultXE = ", resultXE, " \n\r");
	#endif
	
	compare = bdCompare(resultYB, resultXE);
	
	#ifdef PRINT
	EMPTYLINE
	printf("Result of comparsion test %d \n\r", compare);
	#endif
	
	
	if(compare == 0){

		*RESULT = 1;
	}
	else{
		*RESULT = 66;
	}
	
	
	bdFree(&mod);
	bdFree(&x);
	bdFree(&y);
	bdFree(&a_pam);
	bdFree(&b_pam);
	
	bdFree(&resultYA);
	bdFree(&resultYB);
	
	bdFree(&resultXA);
	bdFree(&resultXB);
	bdFree(&resultXC);
	bdFree(&resultXD);
	bdFree(&resultXE);
	
		
	return 0;

}