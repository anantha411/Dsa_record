#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char queue[MAX];
int front=0, rear=-1;
char bfsVisited[MAX];
int bfsTop=-1;

typedef struct Node{
    char city;
    struct Node* next;
} Node;

Node* adj[MAX]; // adjacency list

void addEdge(char u, char v){
    Node *n = malloc(sizeof(Node)); n->city=v; n->next=adj[u-'A']; adj[u-'A']=n;
}

void BFS(char start){
    int vis[26]={0};
    queue[++rear]=start;
    vis[start-'A']=1;
    while(front<=rear){
        char c=queue[front++];
        printf("%c ",c);
        Node *t=adj[c-'A'];
        while(t){ if(!vis[t->city-'A']){queue[++rear]=t->city; vis[t->city-'A']=1;} t=t->next; }
    }
    printf("\n");
}

void DFSUtil(char u, int vis[]){
    vis[u-'A']=1;
    printf("%c ",u);
    Node *t=adj[u-'A'];
    while(t){ if(!vis[t->city-'A']) DFSUtil(t->city,vis); t=t->next; }
}

void DFS(char start){
    int vis[26]={0};
    DFSUtil(start,vis);
    printf("\n");
}

int main(){
    for(int i=0;i<MAX;i++) adj[i]=NULL;
    addEdge('A','B'); addEdge('A','C'); addEdge('B','D'); addEdge('C','E'); addEdge('D','E');

    printf("BFS from A: "); BFS('A');
    printf("DFS from A: "); DFS('A');

    return 0;
}
