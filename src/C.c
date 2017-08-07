#include <stdio.h>
#include <stdlib.h>
#include "C_Test.h"
#include "Config.h"

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

#ifdef QUICK
/* Die Funktion erhält einen Zeiger auf das erste
 * und einen zweiten Zeiger auf das letzte Element.
 * Hier werden dazu die Namen »links« und »rechts« verwendet.
 */
void quick(int *links, int *rechts) {
   int *ptr1 = links;
   int *ptr2 = rechts;
   int w, x;
   /* x bekommt die Anfangsadresse der
    * Mitte von links und rechts.
    * Anstatt der Bitverschiebung hätten Sie
    * auch einfach »geteilt durch 2« rechnen können.
    */
   x = *(links + ((rechts - links) >> 1));
   do {
      while(*ptr1 < x) ptr1++;
      while(*ptr2 > x) ptr2--;
      if(ptr1 > ptr2)
         break;
      w = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = w;
   } while(++ptr1 <= --ptr2);
   if(links < ptr2)  quick(links, ptr2);
   if(ptr1 < rechts) quick(ptr1, rechts);
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
	puts("Initial");
	output(array, 5);

#ifdef BUBBLE
	puts("\nBubble");
	bubblesort(array, 5);
#endif

#ifdef SELECT
	puts("\nSelection");
	selection(array, 5);
#endif

#ifdef QUICK
	puts("\nQuick");
	quick(array, array+5);
#endif

	puts("Sorted");
	output(array, 5);

	//Run tests
	mainTest();

	return EXIT_SUCCESS;
}
