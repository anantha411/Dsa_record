#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char pid[10];
    int burst;
    struct Node *next;
} Node;

void enqueue(Node **front, Node **rear, char pid[], int burst){
    Node *n = malloc(sizeof(Node));
    strcpy(n->pid,pid); n->burst=burst; n->next=NULL;
    if(!*rear) *front=*rear=n;
    else{ (*rear)->next=n; *rear=n; }
    printf("Enqueued: %s\n", pid);
}

Node* dequeue(Node **front, Node **rear){
    if(!*front) return NULL;
    Node *temp = *front;
    *front = (*front)->next;
    if(!*front) *rear=NULL;
    return temp;
}

int main(){
    Node *front=NULL, *rear=NULL;

    enqueue(&front,&rear,"P1",10);
    enqueue(&front,&rear,"P2",5);
    enqueue(&front,&rear,"P3",8);

    Node *p = dequeue(&front,&rear);
    if(p){
        printf("Dequeued: %s (%dms)\n", p->pid, p->burst);
        free(p);
    }

    if(front) printf("Next Process: %s\n", front->pid);

    return 0;
}
