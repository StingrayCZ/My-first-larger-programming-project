#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");

int LamdaSameBIGD(BB RESULT, BB MOD, BB X, BB Y, BB a)
{

	BB cisloX, cisloY, modulus,  a_value; // inner data containers
	BB resultA, resultB, resultC, FIN;    // auxiliary
	
	//assert(RESULT && MOD && X && Y && a);
	
	/* Use temp */
	cisloX = bdNew();
	cisloY = bdNew();
	modulus = bdNew();
	a_value = bdNew();
	
	resultA = bdNew();
	resultB = bdNew();
	resultC = bdNew();
	FIN = bdNew();


	bdSetEqual(cisloX, X); // prirad hodnote cisloX hondotu X
	bdSetEqual(cisloY, Y); // prirad hodnote cisloY hondotu Y
	bdSetEqual(a_value, a);
	bdSetEqual(modulus, MOD);
	
	bdSquare(resultA, cisloX);  // cislo X^2
	
	
	BB AuXNum;
	AuXNum = bdNew();
	bdSetShort(AuXNum, 3);   // 3*
	
	bdMultiply(resultB, resultA, AuXNum);   // 3(X^2)
	
	//free(AuXNum);   // Mazani
	//free(resultA);	// Mazani
	

	bdAdd(resultA, resultB, a_value);      // 3(X^2) + a
	
	//free(a_value);  // Mazani
	//free(resultB);  // Mazani	
	
	bdModulo(resultB, resultA, modulus);                    // (3(X^2) + a) MOD
	
	bdSetShort(AuXNum, 2);
	bdMultiply(resultC, cisloY, AuXNum);        // cislo Y*2
	bdModInv(resultA, resultC, modulus);
	
	bdModMult(FIN, resultA, resultB, modulus);


	bdSetEqual(RESULT, FIN);   
		
	
	bdFree(&cisloX);
	bdFree(&cisloY);
	bdFree(&modulus);
	bdFree(&a_value);
	
	bdFree(&resultA);
	bdFree(&resultB);
	bdFree(&resultC);
	bdFree(&FIN);
	bdFree(&AuXNum);

	return 0;
}