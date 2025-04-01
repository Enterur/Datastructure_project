#include <stdio.h>
#include <stdlib.h>
#include "LinkedPoly.h"

// 공백 다항식 리스트를 생성하는 연산
ListHead* createLinkedList(void) {
    ListHead* L;
    L = (ListHead*)malloc(sizeof(ListHead));
    L->head = NULL;
    return L;
}

// 다항식 리스트에 마지막 노드를 추가하는 연산
void appendTerm(ListHead* L, float coef, int expo) {
    ListNode* newNode;
    ListNode* p;

    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->link = NULL;

    if (L->head == NULL) {
        // 다항식 리스트가 공백일 경우
        L->head = newNode;
        return;
    }
    else {
        // 다항식 리스트가 공백이 아닌 경우
        p = L->head;
        while (p->link != NULL)   // 마지막 노드까지 이동
            p = p->link;

        p->link = newNode;        // 마지막 노드에 연결
    }
}

void addPoly(ListHead* A, ListHead* B, ListHead* C) {
    ListNode* pa = A->head;
    ListNode* pb = B->head;
    float sum;

    while (pa != NULL && pb != NULL) {
        if (pa->expo == pb->expo) {
            sum = pa->coef + pb->coef;
            if (sum != 0.0)
                appendTerm(C, sum, pa->expo);
            pa = pa->link;
            pb = pb->link;
        }
        else if (pa->expo > pb->expo) {
            appendTerm(C, pa->coef, pa->expo);
            pa = pa->link;
        }
        else {
            appendTerm(C, pb->coef, pb->expo);
            pb = pb->link;
        }
    }

    while (pa != NULL) {
        appendTerm(C, pa->coef, pa->expo);
        pa = pa->link;
    }
    while (pb != NULL) {
        appendTerm(C, pb->coef, pb->expo);
        pb = pb->link;
    }
}


void printPoly(ListHead* L) {
    ListNode* p = L->head;
    while (p != NULL) {
        printf("%.0fx^%d", p->coef, p->expo);
        if (p->link != NULL)
            printf(" + ");
        p = p->link;
    }
    printf("\n");
}
