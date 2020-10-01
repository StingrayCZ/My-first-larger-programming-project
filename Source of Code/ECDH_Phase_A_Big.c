#include <stdio.h>
#include <string.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

// Adopted and edited part of library https://www.di-mgt.com.au/bigdigits.html
int RandomNumber(unsigned char *bytes, size_t nbytes, const unsigned char *seed, size_t seedlen)
/* Our own (very insecure) random generator call-back function using good old rand() 
   This demonstrates the required format for BD_RANDFUNC
   -- replace this in practice with your own cryptographically-secure function.
*/
{
	unsigned int myseed;
	size_t i;
	int offset;

	/* Use time - then blend in seed, if any */
	myseed = (unsigned)time(NULL);
	if (seed)
	{
		for (offset = 0, i = 0; i < seedlen; i++, offset = (offset + 1) % sizeof(unsigned))
			myseed ^= ((unsigned int)seed[i] << (offset * 8));
	}

	//srand(myseed);
	srand(PHY_RandomReq());    //  Random number generator by LWM mesh
	while (nbytes--)
	{
		*bytes++ = rand() & 0xFF;
	}

	return 0;
}


int ECDH_PHASE_A_BIGD(BB MOD, BB a_parameter, BB b_parameter, BB results[])
{
	
	// Values BB X_first, BB Y_first, BB G_Order are stored in array  BB results[]
	// Generator of random numbers
	//srand((unsigned int) time(NULL));
	//int64_t Throttle = 30;                 // Throttle of power
	
	
	//assert(MOD && a_parameter && b_parameter && results[]);


	// Values for obtain the first point64_t and order
	BB premod, mod;                      // modulus
	BB cutoff;
	BB a, b;                     // paramereters a and b
	BB Xfirst, Yfirst, OrderG;
	
	uint8_t PrimeTest;
	uint8_t TESTvalue;
	uint8_t ResultPointCheck;
	
	premod = bdNew();
	mod = bdNew();
	cutoff = bdNew();
	premod = bdNew();
	
	a = bdNew();
	b = bdNew();
	
	Xfirst = bdNew();
	Yfirst = bdNew();
	OrderG = bdNew();
	
	bdConvFromHex(cutoff, "12C");  // value of cuttoff
	bdConvFromHex(mod, "c8");  // value is 100
	
	
	do
		{

			// SET of MODULUS
			
			
			do
			{
				// Selection of the modulo value from pseudo-random number
				bdRandomSeeded(premod, 512, (const unsigned char*)"", 0, RandomNumber);  // 512 bits key
				//bdModulo(mod, premod, cutoff);
				
				
				// Examination of modulus
				PrimeTest = bdRabinMiller(mod, 10);   // Rabin-Miller - 10 rounds iteration

			}
			while(PrimeTest == 0);   // This cycle runs until a value appears as 1 (prime)
			
			
			// Selection of asymptos values from pseudo-random number
			bdRandomSeeded(a,192, (const unsigned char*)"", 0, RandomNumber);  // 512 bits key
			bdRandomSeeded(b, 192, (const unsigned char*)"", 0, RandomNumber);  // 512 bits key

			checkValABBIGD(TESTvalue, mod, a, b);  // Application for test
			
			
			// Examination of a and b
			while(TESTvalue == 2)
			{

				bdRandomSeeded(a, 128, (const unsigned char*)"", 0, RandomNumber);  // 128 bits key
				bdRandomSeeded(b, 128, (const unsigned char*)"", 0, RandomNumber);  // 128 bits key
				checkValABBIGD(TESTvalue, mod, a, b);

			}
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Modulus = ", mod, " \n\r");
			bdPrintDecimal("a = ", a, " \n\r");
			bdPrintDecimal("b = ", b, " \n\r");
			#endif // PRINT_ON


			// Input: modulus, a, b
			// Output: Xfirst, Yfirst, OrderG
			TheFirstPointBIGD(mod, a, b, Xfirst, Yfirst, OrderG);
	
			
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Xfirst = ", Xfirst, " \n\r");
			bdPrintDecimal("Xfirst = ", Xfirst, " \n\r");
			bdPrintDecimal("Yfirst = ", OrderG, " \n\r");
			#endif // PRINT_ON
			
		
			VerifyOfPointBIGD(ResultPointCheck, mod, Xfirst, Yfirst, a, b);

	

		}
		while(ResultPointCheck == 66);

	
	// -- Output of results --
	
	bdSetEqual(MOD, mod);
	bdSetEqual(a_parameter, a);
	bdSetEqual(b_parameter, b);
	bdSetEqual(results[0], Xfirst);   // Send value to next process
	bdSetEqual(results[1], Yfirst);   // Send value to next process
	bdSetEqual(results[2], OrderG);   // Send value to next process 
	
	
	bdFree(&mod);
	bdFree(&a);
	bdFree(&Xfirst);
	bdFree(&Yfirst);
	bdFree(&OrderG);
	
	return 0;

}