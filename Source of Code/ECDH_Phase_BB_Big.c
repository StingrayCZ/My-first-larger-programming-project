#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT


int ECDH_PHASE_BB_BIGD(BB MOD, BB a, BB b, BB results[])
{
	BB mod, a_pam, b_pam;
	BB OrderG, SecKey;
	BB X, Y, iterator;
	BB voidValue;   // excess value
	volatile BB container[2];
	BB Xfirst, Yfirst;
	
	uint32_t iteration;
	uint8_t STOPval;
	
	mod = bdNew();
	a_pam = bdNew();
	b_pam = bdNew();
	
	OrderG = bdNew();
	SecKey = bdNew();
	
	X = bdNew();
	Y = bdNew();
	iterator = bdNew();
	
	voidValue = bdNew();
	
	container[0] = bdNew();
	container[1] = bdNew();
	container[2] = bdNew();
	
	Xfirst = bdNew();
	Yfirst = bdNew();
	OrderG = bdNew();
	
	// Set values from prevous applications	
	bdSetEqual(mod, MOD);
	bdSetEqual(a_pam, a);
	bdSetEqual(b_pam, b);


	//Input: mod, a, b
	//Output: Xfirst, Yfirst, OrderG
	TheFirstPointBIGD(mod, a_pam, b_pam, Xfirst, Yfirst, OrderG);
	

	SecretKeyBIGD(OrderG, SecKey);   // Call the application SecretKeyBIGD, obtain pseudo-random number
	
	bdSetEqual(iterator, SecKey);  //  iterator = SecKey
	bdIncrement(iterator);         // iterator = SecKey + 1;
	
	PointCompBIGD(X, Y, a_pam, mod, Xfirst, Yfirst, &iteration, &STOPval);  // Call the application SecretKeyBIGD, obtain pseudo-random number
	
	bdSetEqual(results[0], Xfirst);  // X
	bdSetEqual(results[1], Yfirst);  // Y
	
	
	// FLUSH Objects
	bdFree(&mod);
	bdFree(&a_pam);
	bdFree(&b_pam);
	
	bdFree(&OrderG);
	bdFree(&SecKey);
	
	bdFree(&X);
	bdFree(&Y);
	bdFree(&iterator);
	
	bdFree(&container[0]);
	bdFree(&container[1]);
	bdFree(&container[2]);
	
	bdFree(&Xfirst);
	bdFree(&Yfirst);

	
	return 0;

}