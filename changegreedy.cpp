
#include "changegreedy.hpp"

/*
Function: changegreedy
Parameters: int array, int array, int a, int length
Purpose: Takes a target number a and an array of coin denominations v and
	returns in array c the number of each coin needed to equal the value
	of the target number.
Preconditions: v and c must be the same length.
Side Effects: The contents of array c, if any, will be overwritten.
*/

void changegreedy(int v[], int c[], int a, int length) {
	int tempTotal = a;

	/*This is more efficient, but doesn't as closely adhere to the description
	of this algorithm presented in the project description.

	for (int i = length - 1; i >= 0; --i) {
		c[i] = tempTotal / v[i];
		tempTotal = tempTotal \ v[i];
	}*/

	for (int i = length - 1; i >= 0; --i) {
		c[i] = 0;

		while(v[i] >= tempTotal) {
			c[i]++;
			tempTotal -= v[i];
		}
	}
}
