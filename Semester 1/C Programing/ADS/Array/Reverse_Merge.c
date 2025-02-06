#include <stdio.h>

void main() {
    int n, m;

    // Input size and elements for the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // Input size and elements for the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &m);
    int b[m];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < m; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    // Merging both arrays in reverse order into array 'c'
    int c[n + m], j = 0;
    for (int i = n - 1; i >= 0; i--) {  // Reverse the first array
        c[j++] = a[i];
    }
    for (int i = m - 1; i >= 0; i--) {  // Reverse the second array
        c[j++] = b[i];
    }

    // Displaying merged array
    printf("The merged array with both arrays in reverse order is: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}
