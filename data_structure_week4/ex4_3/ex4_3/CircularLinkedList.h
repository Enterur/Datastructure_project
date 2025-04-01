#pragma once


typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;


typedef struct {
    listNode* head;
} linked_list_h;



linked_list_h* createLinkedList_h(void);
void printList(linked_list_h* CL);
void insertFirstNode(linked_list_h* CL, const char* x);
void insertMiddleNode(linked_list_h* CL, listNode* pre, const char* x);
void deleteNode(linked_list_h* CL, listNode* old);
listNode* searchNode(linked_list_h* CL, const char* x);
