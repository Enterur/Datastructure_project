#include "LinkedPoly.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    ListHead* A, * B, * C;

    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();

    appendTerm(A, 4, 3);
    appendTerm(A, 3, 2);
    appendTerm(A, 5, 1);
    printf("\nA(x) = ");
    printPoly(A);

    appendTerm(B, 3, 3);
    appendTerm(B, 2, 2);
    appendTerm(B, 1, 1);
    appendTerm(B, 2, 0);
    appendTerm(B, 1, 0);

    printf("\nB(x) = ");
    printPoly(B);

    addPoly(A, B, C);
    printf("\nC(x) = ");
    printPoly(C);

    getchar();
    return 0;
}
