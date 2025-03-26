#include <stdio.h>
#include "header.h"

void addcal(int L[], int x, int n) {
	int i, cood = 0;
	for (i = 0; i < n; i++) {
		if (L[i] <= x && x <= L[i + 1]) {
			cood = i + 1;
			break;
		}
	}
	if (i == n) 
		cood = n;

	for (i = n; i > cood; i--) {
		L[i] = L[i - 1];
	}

	L[cood] = x;	
}
void mincal(int L[], int x, int n) {
	int i, cood = n;  
	for (i = 0; i < n; i++) {
		if (L[i] == x) {
			cood = i;
			break;
		}
	}
	for (i = cood; i < n - 1; i++) {
		L[i] = L[i + 1];
	}

}