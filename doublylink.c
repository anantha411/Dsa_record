#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char state[50];
    struct Node *prev, *next;
} Node;

Node* add(Node *tail, char s[]) {
    Node *n = malloc(sizeof(Node));
    strcpy(n->state,s); n->prev=tail; n->next=NULL;
    if(tail) tail->next=n;
    return n;
}

int main() {
    Node *head=NULL, *cur=NULL;
    head = add(NULL,"Doc_v1");
    Node *second = add(head,"Doc_v2");
    Node *third = add(second,"Doc_v3");

    cur = second;
    printf("Current State: %s\n",cur->state);

    // Undo
    if(cur->prev) cur = cur->prev;
    printf("After Undo: %s\n",cur->state);

    // Redo
    if(cur->next) cur = cur->next;
    printf("After Redo: %s\n",cur->state);

    return 0;
}
