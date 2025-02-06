#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Find the minimum value node in a BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find the maximum value node in a BST
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal of the BST (sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal of the BST
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal of the BST
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Find the successor of a node in the BST
struct Node* findSuccessor(struct Node* root, int data) {
    struct Node* current = search(root, data);
    if (!current) return NULL;

    // Case 1: If the node has a right subtree
    if (current->right != NULL) {
        return findMin(current->right);
    }

    // Case 2: No right subtree
    struct Node* successor = NULL;
    struct Node* ancestor = root;
    while (ancestor != current) {
        if (data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// Find the predecessor of a node in the BST
struct Node* findPredecessor(struct Node* root, int data) {
    struct Node* current = search(root, data);
    if (!current) return NULL;

    // Case 1: If the node has a left subtree
    if (current->left != NULL) {
        return findMax(current->left);
    }

    // Case 2: No left subtree
    struct Node* predecessor = NULL;
    struct Node* ancestor = root;
    while (ancestor != current) {
        if (data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

// Function to create multiple nodes at once
struct Node* createMultipleNodes(struct Node* root) {
    int n, value;
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Create Multiple Nodes\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display Inorder Traversal\n");
        printf("6. Display Preorder Traversal\n");
        printf("7. Display Postorder Traversal\n");
        printf("8. Find Successor\n");
        printf("9. Find Predecessor\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createMultipleNodes(root);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value) == NULL) {
                    printf("Element %d is not in the BST.\n", value);
                } else {
                    root = deleteNode(root, value);
                    printf("Element %d deleted from the BST.\n", value);
                }
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* found = search(root, value);
                if (found != NULL) {
                    printf("Value %d found in the BST.\n", value);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;

            case 5:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 8:
                printf("Enter value to find successor: ");
                scanf("%d", &value);
                struct Node* successor = findSuccessor(root, value);
                if (successor != NULL) {
                    printf("Successor of %d is %d.\n", value, successor->data);
                } else {
                    printf("No successor found for %d.\n", value);
                }
                break;

            case 9:
                printf("Enter value to find predecessor: ");
                scanf("%d", &value);
                struct Node* predecessor = findPredecessor(root, value);
                if (predecessor != NULL) {
                    printf("Predecessor of %d is %d.\n", value, predecessor->data);
                } else {
                    printf("No predecessor found for %d.\n", value);
                }
                break;

            case 10:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
