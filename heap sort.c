#include <stdio.h>
#include <string.h>

typedef struct {
    char id[10];
    int priority;
} Job;

void heapify(Job arr[], int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l].priority>arr[largest].priority) largest=l;
    if(r<n && arr[r].priority>arr[largest].priority) largest=r;
    if(largest!=i){
        Job t=arr[i]; arr[i]=arr[largest]; arr[largest]=t;
        heapify(arr,n,largest);
    }
}

void heapSort(Job arr[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--){
        Job t=arr[0]; arr[0]=arr[i]; arr[i]=t;
        heapify(arr,i,0);
    }
}

int main(){
    Job jobs[] = {{"J1",25},{"J2",10},{"J3",40},{"J4",15},{"J5",30}};
    int n=5;

    printf("Before Sorting (Priority): ");
    for(int i=0;i<n;i++) printf("%d ", jobs[i].priority);
    printf("\n");

    heapSort(jobs,n);

    printf("After Heap Sort (Descending): ");
    for(int i=n-1;i>=0;i--) printf("%d ", jobs[i].priority);
    printf("\n");

    printf("Execution Order: ");
    for(int i=n-1;i>=0;i--){ printf("%s",jobs[i].id); if(i>0) printf(" ? "); }
    printf("\n");

    return 0;
}
