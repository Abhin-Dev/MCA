#include<stdio.h>

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

    // Finding maximum and minimum elements
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }

    // Display the results
    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);
}
