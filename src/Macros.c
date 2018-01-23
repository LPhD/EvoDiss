#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"
#include "kconfig.h"
#include "Config.h"

//Test method for macros and partial preprocessor in pure::variants
void test (){

//True for Selection of Feature_A
#if (defined(Feature_A) && (MAKRO(7) > 7))
	puts("\nFeature A and Macro");
#endif

//True for Selection of Feature_B
#if (defined(Feature_B) && (MAKRO(7) > 7))
	puts("\nFeature B and Macro");
#endif

//Never true
#if (defined(Feature_A) && !(MAKRO(7) > 7))
	puts("\nFeature A and not Macro");
#endif

//Always true
#if (defined(Feature_A) || (MAKRO(7) > 7))
	puts("\nFeature A or Macro");
#endif

//True for Selection of Feature_A
#if defined(Feature_A)
	puts("\nFeature A");
#endif

}

//Test method for macros and partial preprocessor
void testMacros(){

//True for selection of BUBBLE
#if(MAKRO(7) > 7) && (IS_ENABLED(BUBBLE) && ENABLED(BUBBLE))
	printf("Die Zahl ist: %i", MAKRO(7));
	//True for selection of BUBBLE
	#ifdef BUBBLE
		puts("\nBubble und Makro!");
	#endif
//False for selection of BUBBLE
#else
	puts("Fehler!");
	//True for define of BUBBLE (def BUBBLE, not def BUBBLE 1)
	#ifdef BUBBLE
		puts("\nBubble ohne Makro!");
	#endif
#endif

//True if BUBBLE == 1
#if IS_ENABLED(BUBBLE)
	printf("\nMakro IS_ENABLED: %i",IS_ENABLED(BUBBLE));
#endif
//True if BUBBLE == 1
#if ENABLED(BUBBLE)
	printf("\nMakro ENABLED: %i",ENABLED(BUBBLE));
#endif

	printf("\nMakro MAKRO(7): %i",MAKRO(7));

#ifdef BUBBLE2
	puts("\nBubble2 selected!");
#endif

	test();
}
