
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* createNode(int value)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
struct node* insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value node
struct node* findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete a node
struct node* deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        // Node has no child or one child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Search a node
void search(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (root->data == value)
        printf("Element found\n");

    else if (value < root->data)
        search(root->left, value);

    else
        search(root->right, value);
}

// Display using Inorder Traversal
void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n\n--- BINARY SEARCH TREE ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Delete operation completed");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 4:
                printf("BST elements: ");
                display(root);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
