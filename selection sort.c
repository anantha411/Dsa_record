#include <stdio.h>

int main(){
    int marks[] = {72,85,63,91,47,89,77};
    int n = 7, i, j, min, temp;

    printf("Before Sorting: ");
    for(i=0;i<n;i++) printf("%d ",marks[i]);
    printf("\n");

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++)
            if(marks[j]<marks[min]) min=j;
        if(min!=i){ temp=marks[i]; marks[i]=marks[min]; marks[min]=temp; }
    }

    printf("After Selection Sort: ");
    for(i=0;i<n;i++) printf("%d ",marks[i]);
    printf("\n");

    return 0;
}
