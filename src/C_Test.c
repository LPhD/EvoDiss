#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Config.h"
#include "C.h"


int compareResults(int *arraySorted, int *arrayExpected, int length){
	int isEqual = 1;
	for (int i = 0; i < length; ++i) {
		if(!(arraySorted[i] == arrayExpected[i])) isEqual = 0;
	}
	if(isEqual == 1){
		puts("Success!");
		return 1;
	} else {
		puts("Fail!");
		return 0;
	}
}

//Runs tests with an array with three elements
void threeElmArray(){
	int arrayTest_1[3] = { 3,2,1 };
	int arrayTest_1_sorted[3] = { 1,2,3 };
#ifdef BUBBLE
	bubblesort(arrayTest_1, 3);
#elif defined SELECT
	selection(arrayTest_1, 3);
#elif defined SHELL
	shellsort(arrayTest_1, 3);
#endif
	if (!compareResults(arrayTest_1, arrayTest_1_sorted, 3)){
#ifdef BUBBLE
		puts("Sorting three elements array with bubblesort failed!");
#elif defined SELECT
		puts("Sorting three elements array with selection sort failed!");
#elif defined SHELL
		puts("Sorting three elements array with SHELLsort failed!");
#endif
	}

}

//Runs tests with an empty array
void zeroElmArray(){
	int arrayTest_2[0] = {};
	int arrayTest_2_sorted[0] = {};
#ifdef BUBBLE
	bubblesort(arrayTest_2, 0);
#elif defined SELECT
	selection(arrayTest_2, 0);
#elif defined SHELL
	shellsort(arrayTest_2, 0);
#endif
	if (!compareResults(arrayTest_2, arrayTest_2_sorted, 0)){
#ifdef BUBBLE
		puts("Sorting empty array with bubblesort failed!");
#elif defined SELECT
		puts("Sorting empty array with selection sort failed!");
#elif defined SHELL
		puts("Sorting empty array with SHELLsort failed!");
#endif
	}

}

//Runs tests with an array with ten elements
void tenElmArray(){
	int arrayTest_3[10] = {7, 3, 12, 3, 4, 1, 9, 3, 0, -1};
	int arrayTest_3_sorted[10] = {-1, 0 , 1, 3, 3, 3, 4, 7, 9, 12};
#ifdef BUBBLE
	bubblesort(arrayTest_3, 10);
#elif defined SELECT
	selection(arrayTest_3, 10);
#elif defined SHELL
	shellsort(arrayTest_3, 10);
#endif
	if (!compareResults(arrayTest_3, arrayTest_3_sorted, 10)){
#ifdef BUBBLE
		puts("Sorting ten elements array with bubblesort failed!");
#elif defined SELECT
		puts("Sorting ten elements array with selection sort failed!");
#elif defined SHELL
		puts("Sorting ten elements array with shellsort failed!");
#endif
	}
}

void mainTest (){
	puts("\nRunning tests...");
	threeElmArray();
	zeroElmArray();
	tenElmArray();
}
