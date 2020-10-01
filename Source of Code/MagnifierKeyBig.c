#include <stdio.h>
#include <string.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

int MagnifierKeyBig(BB Key, BB X, BB Y){
	
	// prevod int na BIGD
	BIGD Xseed, Yseed, KeyPattern;
	BIGD resultA, resultB, num;
	
	uint8_t exponent = 127;
	int8_t comparsion;
	
	
	Xseed = bdNew();
	Yseed = bdNew();
	KeyPattern = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	num = bdNew();

	
	bdSetEqual(Xseed, X);
	bdSetEqual(Yseed, Y);
	
	bdSetShort(num, 2);
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check of input values \n\r");
	bdPrintDecimal("Xseed = ", Xseed, " \n\r");
	bdPrintDecimal("Yseed = ", Yseed, " \n\r");
	#endif
	
	

	bdPower(resultA, num, exponent);   // 2^127
	bdDecrement(KeyPattern);
	
		
	
	bdPrintDecimal("Lenght of key ", KeyPattern, " \n\r");
	
	
	do{
		
		bdMultiply(resultB, Xseed, Yseed);

		comparsion = bdCompare(resultB, KeyPattern);
		
		
		bdSetEqual(Xseed, resultB);

		
	}while(comparsion != 1);
	
	
	bdSetEqual(Key, Xseed);
	
	
	
	#ifdef PRINT
	EMPTYLINE
	printf("Check of input values \n\r");
	bdPrintDecimal("Vypocitany klic", resultB, " \n\r");
	printf("Cislo proovnani %d", comparsion);	bdPrintDecimal("a = ", a, " \n\r");
	#endif
	
	
	// FLUSH objects
	bdFree(&Xseed);
	bdFree(&Yseed);
	bdFree(&KeyPattern);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&num);
	
	return 0;
	
}