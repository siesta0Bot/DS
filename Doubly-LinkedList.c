#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    struct ListNode* next;
    struct ListNode* prev;
    int val;
}ListNode;

void LinkedList_delete(ListNode* head){
    ListNode* temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        printf("going to delete %p\n", temp);
        free(temp);
    }
}

void addNode(ListNode** head, int n){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if(newNode == NULL){
        printf("memory failed\n");
        LinkedList_delete(*head);
        return;
    }
    else{
        printf("node added %p\n", newNode);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = n;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        ListNode* curr = *head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
}


void printNodes(ListNode* head){
    while(head!=NULL){
        if(head->next == NULL){
            printf("%d\n", head->val);
            return;
        }
        else{
            printf("%d ", head->val);
        }
        head = head->next;
    }
}

void inverse_printNodes(ListNode* head){
    ListNode* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    while(curr!=NULL){
        if(curr->prev==NULL){
            printf("%d\n", curr->val);
            return;
        }
        else{
            printf("%d ", curr->val);
        }
        curr = curr->prev;
    }
}

