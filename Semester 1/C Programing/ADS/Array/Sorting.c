#include<stdio.h>

void sortAscending(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                // Swap elements if they're in the wrong order
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void sortDescending(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] < a[j+1]) {
                // Swap elements if they're in the wrong order
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main() {
    int n;

    // Input size and elements for the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // Sort array in ascending order
    sortAscending(a, n);
    printf("Array sorted in ascending order: ");
    display(a, n);

    // Sort array in descending order
    sortDescending(a, n);
    printf("Array sorted in descending order: ");
    display(a, n);
}
