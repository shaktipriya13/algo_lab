#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

// Function to find the minimum element in a tree
treeNode* FindMin(treeNode *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left != NULL) {
        return FindMin(node->left);
    }
    else {
        return node;
    }
}

// Function to insert a node in the tree
treeNode* insert(treeNode *node, int data) {
    if (node == NULL) {
        treeNode *temp = (treeNode *)malloc(sizeof(treeNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data > node->data) {
        node->right = insert(node->right, data);
    }
    else if (data < node->data) {
        node->left = insert(node->left, data);
    }
    return node;
}

// Function to delete a node from the tree
treeNode* deletion(treeNode *node, int data) {
    if (node == NULL) {
        printf("Element Not Found\n");
        return node;
    }
    if (data < node->data) {
        node->left = deletion(node->left, data);
    }
    else if (data > node->data) {
        node->right = deletion(node->right, data);
    }
    else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
        }
        else if (node->left == NULL) {
            treeNode *temp = node;
            node = node->right;
            free(temp);
        }
        else if (node->right == NULL) {
            treeNode *temp = node;
            node = node->left;
            free(temp);
        }
        else {
            treeNode *temp = FindMin(node->right);
            node->data = temp->data;
            node->right = deletion(node->right, temp->data);
        }
    }
    return node;
}

// Function to search for an element in the tree
treeNode* search(treeNode *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data > node->data) {
        return search(node->right, data);
    }
    else if (data < node->data) {
        return search(node->left, data);
    }
    else {
        return node;
    }
}

// Function for in-order traversal
void inorder(treeNode *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Function for pre-order traversal
void preorder(treeNode *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Function for post-order traversal
void postorder(treeNode *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    treeNode *root = NULL;
    int ch, elt;

    do {
        printf("\n### Binary Search Tree Operations ###");
        printf("\n1 - Insertion");
        printf("\n2 - Deletion");
        printf("\n3 - Searching");
        printf("\n4 - Traverse in Inorder");
        printf("\n5 - Traverse in Preorder");
        printf("\n6 - Traverse in Postorder");
        printf("\n7 - Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &elt);
                root = insert(root, elt);
                break;
            case 2:
                printf("Enter element to be deleted: ");
                scanf("%d", &elt);
                root = deletion(root, elt);
                break;
            case 3:
                printf("Enter element to be searched: ");
                scanf("%d", &elt);
                if (search(root, elt) == NULL) {
                    printf("Element NOT found\n");
                }
                else {
                    printf("Element found\n");
                }
                break;
            case 4:
                printf("\nBST Traversal in INORDER: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nBST Traversal in PREORDER: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("\nBST Traversal in POSTORDER: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("\nTerminating\n");
                break;
            default:
                printf("\nInvalid Option! Try Again!\n");
                break;
        }
    } while (ch != 7);

    return 0;
}
