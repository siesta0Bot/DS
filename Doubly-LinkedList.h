#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct ListNode{
    struct ListNode* next;
    struct ListNode* prev;
    int val;
}ListNode;

void LinkedList_delete(ListNode* head);
void addNode(ListNode** head, int n);
void printNodes(ListNode* head);
void inverse_printNodes(ListNode* head);

#endif /* LINKEDLIST_H */
