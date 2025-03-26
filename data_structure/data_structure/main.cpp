#include <stdio.h>
#include "header.h"

int main() {
	int arr[10] = { 10, 20, 30, 50, 60 };
	int x = 40, n = 5;
	printf("ori : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	addcal(arr, x, n);
	n++;

	printf("add : ");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	x = 30;

	mincal(arr, x, n);
	n--;

	printf("min : ");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}