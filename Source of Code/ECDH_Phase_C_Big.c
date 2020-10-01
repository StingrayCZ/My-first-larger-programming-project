#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
#define PRINT


void ECDH_PHASE_C_BIGD(BB Xo, BB Yo, BB MOD, BB a, BB KEY)
{
	
	BB Xa, Ya, mod, a_pam;
	volatile BB results[2];
	BB Xres, Yres, Key;
	
	uint32_t *iteration;
	uint8_t *STOPval;
	
	Xa = bdNew();
	Ya = bdNew();
	mod = bdNew();
	a_pam = bdNew();
	
	results[0] = bdNew();
	results[1] = bdNew();
	results[2] = bdNew();
	
	Key = bdNew();
	Xres = bdNew();
	Yres = bdNew();	
	
	bdSetEqual(Xa, Xo);
	bdSetEqual(Ya, Yo);

	
	bdSetEqual(a_pam, a);
	
	PointCompBIGD(Xa, Ya, a_pam, mod, Xres, Yres, &iteration, &STOPval)
	

	
	MagnifierKeyBig(Key, Xres, Yres);
	
	
	bdSetEqual(KEY ,Key);
	

	// Flush Objects
	bdFree(&Xa);
	bdFree(&Ya);
	bdFree(&mod);
	bdFree(&a_pam);
	
	bdFree(&results[0]);
	bdFree(&results[1]);
	bdFree(&results[2]);
	
	bdFree(&X);
	bdFree(&Y);
	bdFree(&Key);
	
}
