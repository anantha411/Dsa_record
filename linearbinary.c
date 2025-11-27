#include <stdio.h>

int linearSearch(int arr[], int n, int key, int *comp) {
    *comp = 0;
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (arr[i] == key)
            return 1;   
    }
    return 0;           
}

int binarySearch(int arr[], int n, int key, int *comp) {
    int left = 0, right = n - 1;
    *comp = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        (*comp)++;

        if (arr[mid] == key)
            return 1;   
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;           
}

int main() {
    int dataset[] = {102, 215, 310, 420, 515, 630, 745, 860, 975};
    int n = sizeof(dataset) / sizeof(dataset[0]);
    int id, foundL, foundB;
    int compL, compB;

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    
    foundL = linearSearch(dataset, n, id, &compL);

    
    foundB = binarySearch(dataset, n, id, &compB);

    printf("Linear Search Comparisons: %d\n", compL);
    printf("Binary Search Comparisons: %d\n", compB);

    if (foundL)
        printf("Result: Patient Found\n");
    else
        printf("Result: Patient Not Found\n");

    return 0;
}
































