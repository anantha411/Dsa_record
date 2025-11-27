#include <stdio.h>

void merge(int arr[], int l, int m, int r){
    int n1=m-l+1,n2=r-m,L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){ if(L[i]<=R[j]) arr[k++]=L[i++]; else arr[k++]=R[j++]; }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int deptA[]={102,118,125,145};
    int deptB[]={101,120,132,150,170};
    int nA=4, nB=5, n=nA+nB;
    int all[n];

    for(int i=0;i<nA;i++) all[i]=deptA[i];
    for(int i=0;i<nB;i++) all[nA+i]=deptB[i];

    mergeSort(all,0,n-1);

    printf("Merged and Sorted IDs: ");
    for(int i=0;i<n;i++) printf("%d ",all[i]);
    printf("\n");

    return 0;
}
