#include <stdio.h>
#include <stdlib.h>
#include "C_Test.h"



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
	puts("Sorted");
	output(array,length);
}

void bubblesortReversed(int *array, int length) {
	int i, j;
	for (i = 0; i < length - 1; ++i) {
		for (j = 0; j < length - i - 1; ++j) {
			if (array[j] < array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	puts("Sorted");
	output(array,length);
}


void output(int *array, int length) {
	puts("Array:");
	for (int var = 0; var < length; ++var) {
		printf("%i \n", array[var]);
	}
}

int main(void) {
	int array[5] = { 5, 3, 1, 2, 4 };
	int length = sizeof(array) / sizeof(int);
	printf("%i", length);

	puts("Initial");
	output(array, length);

	puts("\nBubble");
	bubblesort(array, length);

	puts("\nBubbleReversed");
	bubblesortReversed(array, length);

	//Run tests
	mainTest();

	return EXIT_SUCCESS;
}
