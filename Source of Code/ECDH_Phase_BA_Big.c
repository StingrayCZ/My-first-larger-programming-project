#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT

int ECDH_PHASE_BA_BIGD(BB Order, BB Xf, BB Yf, BB a, BB MOD, BB results[])
{

	BB OrderG, SecKey;
	BB X, Y, a_asymptote, mod, iterator;
	volatile BB container[2];
	BB resultA, resultB;
	BB ResultX, ResultY;
	
	
	unsigned char s[100];
	uint32_t iter, STOPval;
	
	OrderG = bdNew();
	SecKey = bdNew();
	
	X = bdNew();
	Y = bdNew();
	a_asymptote = bdNew();
	mod = bdNew();
	iterator = bdNew();
	
	container[0] = bdNew();
	container[1] = bdNew();
	container[2] = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	
	ResultX = bdNew();
	ResultY = bdNew();
	
	bdSetEqual(OrderG, Order);
	bdSetEqual(X, Xf);
	bdSetEqual(Y, Yf);
	bdSetEqual(a_asymptote, a);
	bdSetEqual(mod, MOD);
	
	
	
	SecretKeyBIGD(OrderG, SecKey);   // Call the application SecretKeyBIGD, obtain pseudo-random number
	
	bdSetEqual(iterator, SecKey);  //  iterator = SecKey
	bdIncrement(iterator);         // iterator = SecKey + 1;
	
	bdConvToDecimal(iterator, s, sizeof(s));
	iter = atoi(s);
	
	
	PointCompBIGD(X, Y, a_asymptote, mod, ResultX, ResultY, &iter, &STOPval);
	
	bdSetEqual(results[0], ResultX);
	bdSetEqual(results[1], ResultY);
	
	bdFree(&OrderG);
	bdFree(&SecKey);
	
	bdFree(&X);
	bdFree(&Y);
	bdFree(&a_asymptote);
	bdFree(&mod);
	bdFree(&iterator);
	
	bdFree(&container[0]);
	bdFree(&container[1]);
	bdFree(&container[2]);
	
	bdFree(&resultA);
	bdFree(&resultB);
	
	return 0;

}