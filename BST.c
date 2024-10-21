#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create(struct Node *root, int data);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);
struct Node *search(struct Node *root, int data);
int countTotalNodes(struct Node *root);
int countInternalNodes(struct Node *root);
struct Node *deleteNode(struct Node *root, int data);
int findMin(struct Node *root); 
int findMax(struct Node *root); 

void main() {
    struct Node *root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n\n--- Menu ---");
        printf("\n1. Insert a node");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search a node");
        printf("\n6. Delete a node");
        printf("\n7. Count total number of nodes");
        printf("\n8. Count internal nodes");
        printf("\n9. Find minimum value");
        printf("\n10. Find maximum value");
        printf("\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = create(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
                
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
                
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
                
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Search successful: Node with value %d found", data);
                } else {
                    printf("Node with value %d not found", data);
                }
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Inorder Traversal after deletion: ");
                inorder(root);
                break;
            case 7:
                printf("Total number of nodes: %d", countTotalNodes(root));
                break;
            case 8:
                printf("Total number of internal nodes: %d", countInternalNodes(root));
                break;
            case 9:
                if (root != NULL) {
                    printf("Minimum value in the tree: %d", findMin(root));
                } else {
                    printf("Tree is empty");
                }
                break;
            case 10:
                if (root != NULL) {
                    printf("Maximum value in the tree: %d", findMax(root));
                } else {
                    printf("Tree is empty");
                }
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
}

struct Node *create(struct Node *root, int data) {
    if (root == NULL) {
        struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
        nn->data = data;
        nn->left = NULL;
        nn->right = NULL;
        root = nn;
    } else {
        if (data < root->data) {
            root->left = create(root->left, data);
        } else {
            root->right = create(root->right, data);
        }
    }
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root) {
    if (root != NULL) {
		printf("%d ", root->data);
        preorder(root->left);
        
        preorder(root->right);
    }
}
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
       
        postorder(root->right);
         printf("%d ", root->data);
    }
}

struct Node *search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int countTotalNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
    }
}

int countInternalNodes(struct Node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    } else {
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
}

int findMin(struct Node *root) {
    struct Node *current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int findMax(struct Node *root) {
    struct Node *current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
