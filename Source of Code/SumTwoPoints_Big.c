#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT

int SumTwoPointsBIGD(BB Xa, BB Ya, BB Xb, BB Yb, BB MOD, BB a_pam, BB results[])
{

	BB mod, a, Xi, Yi, Xj, Yj;
	BB lambda;
	BB Xf, Yf;
	uint8_t DecisionVal;
	
	mod = bdNew();
	a = bdNew();
	Xi = bdNew();
	Yi = bdNew();
	Xj = bdNew();
	Yj = bdNew();
	
	lambda = bdNew();
	
	Xf = bdNew();
	Yf = bdNew();
	
	
	bdSetEqual(mod, MOD);
	bdSetEqual(a, a_pam);
	bdSetEqual(Xi, Xa);
	bdSetEqual(Yi, Ya);
	bdSetEqual(Xj, Xb);
	bdSetEqual(Yj, Yb);

	RecogniserBIGD(&DecisionVal, Xi, Yi, Xj, Yj);


	if(DecisionVal == 1)
	{
		
		LamdaSameBIGD(lambda, mod, Xi, Yi, a);
		
		XSameBIGD(Xf, mod, lambda, Xi);
		
		YUniBIGD(Yf, mod, lambda, Xi, Yi, Xf);
		
	}

	else if(DecisionVal == 2)
	{
		LamdaDiffBIGD(lambda, mod, Xi, Yi, Xj, Yj);
		
		XDiffBIGD(Xf, mod, lambda, Xi, Xj);
		
		YUniBIGD(Yf, mod, lambda, Xi, Yi, Xf);


	}

	// return values
	bdSetEqual(results[0], Xf);
	bdSetEqual(results[1], Yf);
	
	
	// FLUSH objects
	bdFree(&mod);
	bdFree(&a);
	bdFree(&Xi);
	bdFree(&Yi);
	bdFree(&Xj);
	bdFree(&Yj);
	
	bdFree(&lambda);
	
	bdFree(&Xf);
	bdFree(&Yf);

	return 0;

}
