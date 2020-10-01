//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
///////BIG N libs///////
//#include "BigN/bigd.h"
//#include "BigN/bigdRand.h"
//#define BB BIGD
//#define EMPTYLINE printf("\n\r");
//
//
//int YSameBIGD(BB RESULT, BB MOD, BB Lambda, BB X, BB Y, BB X_k)
//{
//
	//BB modulus, lambda, x, y, x_k;
	//BB resultA, resultB, resultC, FIN;    // auxiliary
	//
	////assert(RESULT && MOD && Lambda && X && Y && X_k);
	//
	//modulus = bdNew();
	//lambda = bdNew();
	//x = bdNew();
	//y = bdNew();
	//x_k = bdNew();
	//
	//resultA = bdNew();
	//resultB = bdNew();
	//resultC = bdNew();
	//FIN = bdNew();
	//
	//
	//bdSetEqual(modulus, MOD);
	//bdSetEqual(lambda, Lambda);
	//bdSetEqual(x, X);
	//bdSetEqual(y, Y);
	//bdSetEqual(x_k, X_k);
	//
//
	//bdSubtract(resultA, x, x_k);
	//
	//bdMultiply(resultB, lambda, resultA);
	//
	//bdSubtract(resultC, resultB, y);
	//
	//bdModulo(FIN, resultC, modulus);
//
	//
		//bdFree(&modulus);
		//bdFree(&lambda);
		//bdFree(&x);
		//bdFree(&y);
		//bdFree(&x_k);
		//
		//bdFree(&resultA);
		//bdFree(&resultB);
		//bdFree(&resultC);
		//bdFree(&FIN);
//
	//return 0;
//}