#include <stdio.h>
#include <stdlib.h>

int a[100], size = 0;

void create();
void insert();
void delete();
void search();
void reverse();
void sort();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n---ARRAY OPERATIONS---\n1. Create\n2. Insert\n3. Delete\n4. Search\n5. Reverse\n6. Sort\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: delete(); break;
            case 4: search(); break;
            case 5: reverse(); break;
            case 6: sort(); break;
            case 7: display(); break;
            case 8: 
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

// Function to create the array
void create() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to insert an element
void insert() {
    int element, pos, choice;
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("1. At beginning\n2. At end\n3. At position\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (int i = size; i > 0; i--) {
                a[i] = a[i - 1];
            }
            a[0] = element;
            size++;
            break;
        case 2:
            a[size++] = element;
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            if (pos < 1 || pos > size + 1) {
                printf("Invalid position.\n");
            } else {
                for (int i = size; i >= pos; i--) {
                    a[i] = a[i - 1];
                }
                a[pos - 1] = element;
                size++;
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Function to delete an element
void delete() {
    int choice, pos;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("1. Delete at beginning\n2. Delete at end\n3. Delete at position\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (int i = 0; i < size - 1; i++) {
                a[i] = a[i + 1];
            }
            size--;
            break;
        case 2:
            size--;
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            if (pos < 1 || pos > size) {
                printf("Invalid position.\n");
            } else {
                for (int i = pos - 1; i < size - 1; i++) {
                    a[i] = a[i + 1];
                }
                size--;
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Function to search an element
void search() {
    int element, found = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    for (int i = 0; i < size; i++) {
        if (a[i] == element) {
            printf("%d found at position %d\n", element, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%d not found in the array.\n", element);
    }
}

// Function to reverse the array
void reverse() {
    int left = 0, right = size - 1, temp;
    while (left < right) {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
    printf("Array reversed.\n");
}

// Function to sort the array
void sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

// Function to display the array
void display() {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
