#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

Node* create(int d){
    Node *n = malloc(sizeof(Node));
    n->data = d; n->left = n->right = NULL;
    return n;
}

Node* insert(Node *root, int d){
    if(!root) return create(d);
    if(d < root->data) root->left = insert(root->left,d);
    else root->right = insert(root->right,d);
    return root;
}

void inorder(Node *r){ if(r){ inorder(r->left); printf("%d ",r->data); inorder(r->right); } }
void preorder(Node *r){ if(r){ printf("%d ",r->data); preorder(r->left); preorder(r->right); } }
void postorder(Node *r){ if(r){ postorder(r->left); postorder(r->right); printf("%d ",r->data); } }

int main(){
    int arr[]={10,5,15,3,7,12,18};
    Node *root=NULL;
    for(int i=0;i<7;i++) root = insert(root, arr[i]);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    return 0;
}
