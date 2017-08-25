#include <stdio.h>
#include <stdlib.h>
#include "C_Test.h"
#include "Config.h"
#include "kconfig.h"
#include "Not_kconfig.h"

#ifdef BUBBLE
void bubblesort(int *array, int length) {
	int i, j;
	for (i = 0; i < length - 1; ++i) {
		for (j = 0; j < length - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
#endif

#ifdef SELECT
void selection(int *array, int length) {
	length = length - 1;
	int index, index_small, content, content_small;

	for (index = 0; index < length; index++) {
		content = index;
		for (index_small = index + 1; index_small <= length; index_small++) {
			if (array[index_small] < array[content])
				content = index_small;
		}
		if (content != index) {
			content_small = array[content];
			array[content] = array[index];
			array[index] = content_small;
		}
	}
}
#endif

#ifdef SHELL
void shellsort(int *array, int length) {
  int i, j, temp, n;
   /* Anfangswert für die Distanz errechnen */
  for ( n = 1; n <= length/9; n = 3*n+1);
  for (; n > 0; n /= 3) {
     for (i = n; i <= length; i++) {
        temp = array[i];
        for(j = i; j >= n && array[j-n] > temp; j -= n) {
           array[j] = array[j-n];
        }
        array[j] = temp;
     }
  }
}
#endif


void output(int *array, int length) {
	puts("Array:");
	for (int var = 0; var < length; ++var) {
		printf("%i \n", array[var]);
	}
}

int main(void) {
	int array[5] = { 5, 3, 1, 2, 4 };
	//puts("Initial");
	//output(array, 5);

#ifdef BUBBLE
	//puts("\nBubble");
	//bubblesort(array, 5);
#endif

#ifdef SELECT
	puts("\nSelection");
	selection(array, 5);
#endif

#ifdef SHELL
	puts("\nShell");
	shellsort(array, 5);
#endif

	//puts("Sorted");
	//output(array, 5);

	//Run tests
	//mainTest();
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

	return EXIT_SUCCESS;
}
