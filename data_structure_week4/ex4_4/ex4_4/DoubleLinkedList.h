#pragma once

typedef struct ListNode {
    struct ListNode* llink;
    char data[4];
    struct ListNode* rlink;
} listNode;

typedef struct {
    listNode* head;
} linked_list_h;

linked_list_h* createLinkedList_h(void);
void printList(linked_list_h* DL);
void insertNode(linked_list_h* DL, listNode* pre, const char* x);
void deleteNode(linked_list_h* DL, listNode* old);
listNode* searchNode(linked_list_h* DL, const char* x);
