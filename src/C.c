#include <stdio.h>
#include <stdlib.h>
#define SELECT

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

	puts("Sorted");
	output(array, 5);
	return EXIT_SUCCESS;
}
