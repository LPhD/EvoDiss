#include <stdio.h>
#include <stdlib.h>
#include "kconfig.h"
#include "Config.h"

#define MAKRO(y) MAKRO2(y##1)
#define MAKRO2(y) MAKRO3(y##2)
#define MAKRO3(y) y##3

#define BUBBLE2 BUBBLE


void testMacros(){

#if(MAKRO(7) > 7) && (IS_ENABLED(BUBBLE))
	printf("Die Zahl ist: %i", MAKRO(7));
#ifdef BUBBLE
	puts("\nBubble und Makro!");
#endif
#else
	puts("Fehler!");
#ifdef BUBBLE
	puts("\nBubble ohne Makro!");
#endif
#endif

printf("Makro IS_ENABLED: %i",IS_ENABLED(BUBBLE));
printf("\nMakro MAKRO(7): %i",MAKRO(7));

#ifdef BUBBLE2
	puts("\nBubble selected!");
#endif
}
