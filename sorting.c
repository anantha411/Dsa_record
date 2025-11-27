#include <stdio.h>
#include <time.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

int partition(int arr[],int low,int high){
    int pivot=arr[high],i=low-1;
    for(int j=low;j<high;j++){if(arr[j]<=pivot){i++;swap(&arr[i],&arr[j]);}}
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){ if(L[i]<=R[j]) arr[k++]=L[i++]; else arr[k++]=R[j++]; }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int marks[]={76,45,89,62,55,91,73};
    int n=7, arr1[7], arr2[7];
    for(int i=0;i<n;i++){arr1[i]=arr2[i]=marks[i];}

    clock_t t1=clock(); quickSort(arr1,0,n-1); t1=clock()-t1;
    clock_t t2=clock(); mergeSort(arr2,0,n-1); t2=clock()-t2;

    printf("Sorted List: [");
    for(int i=0;i<n;i++){printf("%d",arr2[i]); if(i<n-1) printf(", ");} printf("]\n");

    printf("Quick Sort Time: %.5fs\n",(double)t1/CLOCKS_PER_SEC);
    printf("Merge Sort Time: %.5fs\n",(double)t2/CLOCKS_PER_SEC);

    return 0;
}
