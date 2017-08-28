#include <stdio.h>
#include <stdlib.h>
#include "kconfig.h"
#include "Config.h"
#include "Makros.h"


void testMakros(){

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

printf("Makro: %i",IS_ENABLED(BUBBLE));

#ifdef BUBBLE2
	puts("\nBubble selected!");
#endif
}
