#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char song[50];
    struct Node *next;
} Node;

void add(Node **h, char s[]) {
    Node *n = malloc(sizeof(Node));
    strcpy(n->song, s); n->next = NULL;
    if(!*h) *h = n;
    else { Node *t = *h; while(t->next) t=t->next; t->next=n; }
}

void delete(Node **h, char s[]) {
    Node *t=*h, *p=NULL;
    while(t && strcmp(t->song,s)!=0){p=t; t=t->next;}
    if(!t) return;
    if(!p) *h=t->next; else p->next=t->next;
    free(t);
}

void display(Node *h){
    while(h){printf("%s",h->song); if(h->next) printf(" ? "); h=h->next;}
    printf("\n");
}

int main(){
    Node *pl=NULL;
    add(&pl,"Shape of You");
    add(&pl,"Blinding Lights");
    add(&pl,"Believer");
    printf("After Adding: "); display(pl);
    delete(&pl,"Blinding Lights");
    printf("After Deleting: "); display(pl);
    return 0;
}
