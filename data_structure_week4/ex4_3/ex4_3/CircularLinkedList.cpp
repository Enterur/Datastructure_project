#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

linked_list_h* createLinkedList_h(void) {
    linked_list_h* CL;
    CL = (linked_list_h*)malloc(sizeof(linked_list_h));
    CL->head = NULL;
    return CL;
}

void printList(linked_list_h* CL) {
    listNode* p;
    printf("CL = (");
    p = CL->head;

    if (p == NULL) {
        printf(")\n");
        return;
    }

    do {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->head) printf(", ");
    } while (p != CL->head);

    printf(")\n");
}

void insertFirstNode(linked_list_h* CL, const char* x) {
    listNode* newNode, * temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (CL->head == NULL) {
        newNode->link = newNode;
        CL->head = newNode;
    }
    else {
        temp = CL->head;
        while (temp->link != CL->head)
            temp = temp->link;
        newNode->link = temp->link;
        temp->link = newNode;
        CL->head = newNode;
    }
}

void insertMiddleNode(linked_list_h* CL, listNode* pre, const char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (CL->head == NULL) {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deleteNode(linked_list_h* CL, listNode* old) {
    listNode* pre;
    if (CL->head == NULL) return;
    if (CL->head->link == CL->head) {
        free(CL->head);
        CL->head = NULL;
        return;
    }
    else if (old == NULL) return;
    else {
        pre = CL->head;
        while (pre->link != old)
            pre = pre->link;

        pre->link = old->link;
        if (old == CL->head)
            CL->head = old->link;
        free(old);
    }
}

listNode* searchNode(linked_list_h* CL, const char* x) {
    listNode* temp;
    temp = CL->head;
    if (temp == NULL) return NULL;

    do {
        if (strcmp(temp->data, x) == 0) return temp;
        temp = temp->link;
    } while (temp != CL->head);
    return NULL;
}
