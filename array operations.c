#include <stdio.h>

int main(){
    int arr[20]={45,32,67,89,23}, n=5, i, pos, val;

    printf("Initial Quantities: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    // Insert 50 at position 3
    val=50; pos=3;
    for(i=n;i>=pos;i--) arr[i]=arr[i-1];
    arr[pos-1]=val; n++;
    printf("After Inserting %d at position %d: ",val,pos);
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    // Delete element at position 2
    pos=2;
    for(i=pos-1;i<n-1;i++) arr[i]=arr[i+1];
    n--;
    printf("After Deleting element at position %d: ",pos);
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    // Search for quantity 89
    val=89;
    for(i=0;i<n;i++) if(arr[i]==val) break;
    if(i<n) printf("Element %d found at position %d\n",val,i+1);

    printf("Final Quantities: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    return 0;
}
