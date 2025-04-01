#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

linked_list_h* createLinkedList_h(void) {
    linked_list_h* DL;
    DL = (linked_list_h*)malloc(sizeof(linked_list_h));
    DL-> head = NULL;
    return DL;
}

void printList(linked_list_h* DL) {
    listNode* p;
    printf("DL = ");
    p = DL->head;

    while (p != NULL) {
        printf("[%s] <-> ", p->data);
        p = p->rlink;
    }

    printf("NULL\n");
}

void insertNode(linked_list_h* DL, listNode* pre, const char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (DL->head == NULL) {
        DL->head = newNode;
    }
    else if (pre == NULL) {
        newNode->rlink = DL->head;
        DL->head->llink = newNode;
        DL->head = newNode;
    }
    else {
        newNode->rlink = pre->rlink;
        if (pre->rlink != NULL)
            pre->rlink->llink = newNode;
        newNode->llink = pre;
        pre->rlink = newNode;
    }
}

void deleteNode(linked_list_h* DL, listNode* old) {
    if (DL->head == NULL) return;
    else if (old == NULL) return;
    else {
        if (old->llink != NULL)
            old->llink->rlink = old->rlink;
        else
            DL->head = old->rlink;

        if (old->rlink != NULL)
            old->rlink->llink = old->llink;

        free(old);
    }
}

listNode* searchNode(linked_list_h* DL, const char* x) {
    listNode* temp;
    temp = DL->head;

    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->rlink;
    }

    return temp;
}
