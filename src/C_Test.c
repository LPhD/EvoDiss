#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int arrayTest_1_sortedASC[3] = { 1,2,3 };
	int arrayTest_1_sortedDESC[3] = { 3,2,1 };
	bubblesort(arrayTest_1, 3);
	if (!compareResults(arrayTest_1, arrayTest_1_sortedASC, 3)){
		puts("Sorting three elements array ascending failed!");
	}
	bubblesortReversed(arrayTest_1, 3);
	if (!compareResults(arrayTest_1, arrayTest_1_sortedDESC, 3)){
		puts("Sorting three elements array descending failed!");
	}
}

//Runs tests with an empty array
void zeroElmArray(){
	int arrayTest_2[0] = {};
	int arrayTest_2_sortedASC[0] = {};
	int arrayTest_2_sortedDESC[0] = {};
	bubblesort(arrayTest_2, 0);
	if (!compareResults(arrayTest_2, arrayTest_2_sortedASC, 0)){
		puts("Sorting empty elements array ascending failed!");
	}
	bubblesortReversed(arrayTest_2, 0);
	if (!compareResults(arrayTest_2, arrayTest_2_sortedDESC, 0)){
		puts("Sorting empty elements array descending failed!");
	}
}

//Runs tests with an array with ten elements
void tenElmArray(){
	int arrayTest_3[10] = {7, 3, 12, 3, 4, 1, 9, 3, 0, -1};
	int arrayTest_3_sortedASC[10] = {-1, 0 , 1, 3, 3, 3, 4, 7, 9, 12};
	int arrayTest_3_sortedDESC[10] = {12, 9, 7, 4, 3, 3, 3, 1, 0, -1};
	bubblesort(arrayTest_3, 10);
	if (!compareResults(arrayTest_3, arrayTest_3_sortedASC, 10)){
		puts("Sorting ten elements array ascending failed!");
	}
	bubblesortReversed(arrayTest_3, 10);
	if (!compareResults(arrayTest_3, arrayTest_3_sortedDESC, 10)){
		puts("Sorting ten elements array descending failed!");
	}
}

void mainTest (){
	puts("\nRunning tests...");
	threeElmArray();
	zeroElmArray();
	tenElmArray();
}
