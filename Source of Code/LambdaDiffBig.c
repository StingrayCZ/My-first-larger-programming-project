#include <stdio.h>
#include <assert.h>

/////BIG N libs///////
#include "BigN/bigd.h"
#include "BigN/bigdRand.h"
#define BB BIGD
#define EMPTYLINE printf("\n\r");
//#define PRINT

int LamdaDiffBIGD(BB RESULT, BB MOD, BB Xi, BB Yi, BB Xj, BB Yj)
{

		BB XA, YA, XB, YB, mod;
		BB resultA, resultAA, resultAAA, resultB, resultBB, resultBBB, resultC, resultD;
		
		
		//assert(RESULT && MOD && Xi && Yi && Xj && Yj);
		
		int compare;
		
		
		XA = bdNew();
		YA = bdNew();
		XB = bdNew();
		YB = bdNew();
		mod = bdNew();
		
		
		resultA = bdNew();
		resultAA = bdNew();
		resultAAA = bdNew();
		resultB = bdNew();
		resultBB = bdNew();
		resultBBB = bdNew();
		resultC = bdNew();
		resultD = bdNew();
		
		
		bdSetEqual(XA, Xi);
		bdSetEqual(YA, Yi);
		bdSetEqual(XB, Xj);
		bdSetEqual(YB, Yj);
		bdSetEqual(mod, MOD);
	
	
		
		////////////////////////////////////////////////////////////////////////////////
		// Y PART
		compare = bdCompare(YB, YA);
		
		if(compare == 1){
			
			bdSubtract(resultA, YB, YA);   // a - b = kladne cislo
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("A je vetsi, vysledek a - b = ", resultA, " \n\r");			
			#endif
			
			bdModulo(resultAAA, resultA, mod);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Zbytek po deleni kladneho cisla 355", resultAAA, " \n\r");
			#endif
			
		}
		
		else if(compare == (-1)){
			
				
			bdSubtract(resultA, YA, YB);   // b - a = kladne cislo
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("B je vetsi, vysledek b - a  = ", resultA, " \n\r");
			#endif
			
			bdModulo(resultAA, resultA, mod);
			
			bdSubtract(resultAAA, mod, resultAA);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Zbytek po deleni zaporneho cisla - 355", resultAAA, " \n\r");
			#endif
		}
		
		
		/////////////////////////////////////////////////////////////////////////
		// X PART
		compare = bdCompare(XB, XA);
		
		if(compare == 1){
			
			bdSubtract(resultB, XB, XA);   // a - b = kladne cislo
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("A je vetsi, vysledek a - b = ", resultB, " \n\r");
			#endif
			
			bdModInv(resultBBB, resultB, mod);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Zbytek po deleni kladneho cisla 355", resultBBB, " \n\r");
			#endif
			
			
		}
		
		else if(compare == (-1)){
			
						
			bdSubtract(resultB, XA, XB);   // b - a = kladne cislo
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("B je vetsi, vysledek b - a  = ", resultA, " \n\r");
			#endif
			
			bdModInv(resultBB, resultB, mod);
			
			bdSubtract(resultBBB, mod, resultBB);
			
			#ifdef PRINT
			EMPTYLINE
			bdPrintDecimal("Zbytek po deleni zaporneho cisla - 355", resultBBB, " \n\r");
			#endif
			
		}
		
		
		bdMultiply(resultC, resultAAA, resultBBB);
		
		bdModulo(resultD, resultC, mod);
		
		
		bdSetEqual(RESULT, resultD);   
		
		
		bdFree(&XA);
		bdFree(&YA);
		bdFree(&XB);
		bdFree(&YB);
		bdFree(&mod);
		
		bdFree(&resultA);
		bdFree(&resultAA);
		bdFree(&resultAAA);
		bdFree(&resultB);
		bdFree(&resultBB);
		bdFree(&resultBBB);
		bdFree(&resultC);
		bdFree(&resultD);


	return 0;
}