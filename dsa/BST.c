#include <stdio.h>
#include <stdlib.h>

// 1. Define the Structure of the Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 2. Function to Insert a Node into the BST
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Note: Duplicate keys are usually ignored in standard BSTs or handled specifically.
    // This implementation ignores duplicates.

    return root;
}

// 3. Traversal Functions
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// 4. Search Function
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Main Driver Code
int main() {
    struct Node* root = NULL;
    int choice, n, i, data, key;
    struct Node* searchResult = NULL;

    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Create BST (Insert N Integers)\n");
        printf("2. Traverse BST (Inorder, Preorder, Postorder)\n");
        printf("3. Search for a Key\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of integers to insert (N): ");
                scanf("%d", &n);
                printf("Enter %d integers:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                printf("Nodes inserted successfully.\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("\nInorder Traversal:   ");
                    inorder(root);
                    
                    printf("\nPreorder Traversal:  ");
                    preorder(root);
                    
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                searchResult = search(root, key);
                if (searchResult != NULL) {
                    printf("Result: Key %d FOUND in the BST.\n", key);
                } else {
                    printf("Result: Key %d NOT FOUND in the BST.\n", key);
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
