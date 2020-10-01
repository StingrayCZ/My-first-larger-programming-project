#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");

int XSameBIGD(BB RESULT, BB MOD, BB Lambda, BB X)
{
	
	//assert(RESULT && MOD && Lambda && X);
	
	int compare;
	
	BB mod, lambda, x;
	BB nasobitel, resultA, resultB, resultC, resultD, resultE;
	
	
	
	mod = bdNew();
	lambda= bdNew();
	x = bdNew();
	
	nasobitel = bdNew();
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	resultD = bdNew();
	resultE = bdNew();
	
	bdConvFromHex(nasobitel, "2");
		
	bdSetEqual(mod, MOD);
	bdSetEqual(lambda, Lambda);
	bdSetEqual(x, X);
	
	
	bdSquare(resultA, lambda);
	
	bdMultiply(resultB, nasobitel, X);   // 2*x
		
	compare = bdCompare(resultA, resultB);
	
	
	if(compare == 1){
		
		bdSubtract(resultC, resultA, resultB);
		
		bdModulo(resultE, resultC, mod);
	}
	
	else if(compare == (-1)){
		
		bdSubtract(resultC, resultB, resultA);
		
		bdModulo(resultD, resultC, mod);
		
		bdSubtract(resultE, mod, resultD);
		
	}
		
		bdSetEqual(RESULT, resultE);  
		
		
	bdFree(&mod);
	bdFree(&lambda);
	bdFree(&x);
	
	bdFree(&nasobitel);
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&resultD);
	bdFree(&resultE);

	return 0;
}