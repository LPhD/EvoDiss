#ifndef C_H_
#define C_H_

#ifdef BUBBLE
void bubblesort(int *array, int length);
#endif
#ifdef SELECT
void selection(int *array, int length);
#endif
#ifdef SHELL
void shellsort(int *array, int length);
#endif
void output(int *array, int length) ;

#endif
