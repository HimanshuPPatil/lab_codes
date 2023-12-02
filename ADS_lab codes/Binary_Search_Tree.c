#include <stdio.h>
#include <stdlib.h>
int count;
struct node
{
    int data;
    struct node *left; 
    struct node *right;
} *root = NULL;

struct node *Create(int Data)
{
    struct node *temp1;
    temp1 = malloc(sizeof(struct node));
    temp1->left = NULL;
    temp1->right = NULL;
    temp1->data = Data;
    return temp1;
}

void Insert(struct node *temp, int data1)
{
    if (temp == NULL)
    {
        root = Create(data1);
        printf("Element Inserted\n");
    }
    else if (temp->data < data1)
    {
        if (temp->right != NULL)
            Insert(temp->right, data1);
        else
        {
            struct node *temp2;
            temp2 = Create(data1);
            temp->right = temp2;
            printf("Element inserted\n");
        }
    }
    else if (temp->data >= data1)
    {
        if (temp->left != NULL)
            Insert(temp->left, data1);
        else
        {
            struct node *temp2;
            temp2 = Create(data1);
            temp->left = temp2;
            printf("Element inserted\n");
        }
    }
}
void Inorder(struct node *temp)
{
    if (temp)
    {
        Inorder(temp->left);
        printf("%d ", temp->data);
        Inorder(temp->right);
    }
}
void Preorder(struct node *temp)
{
    if (temp)
    {
        printf("%d ", temp->data);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
void Postorder(struct node *temp)
{
    if (temp)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d ", temp->data);
    }
}
void LeafNode(struct node *temp)
{
    if (temp)
    {
        LeafNode(temp->left);
        if (temp->left == NULL && temp->right == NULL)
            printf(" %d", temp->data);
        LeafNode(temp->right);
    }
}
void CountNode(struct node *temp)
{
    if (temp)
    {
        CountNode(temp->left);
        count++;
        CountNode(temp->right);
    }
}
void Mirror(struct node *node1)
{
    if (node1)
    {
        Mirror(node1->left);
        Mirror(node1->right);
        struct node *temp;
        temp = node1->right;
        node1->right = node1->left;
        node1->left = temp;
    }
}
int maxDepth(struct node *node1)
{
    if (node1 == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node1->left);
        int rDepth = maxDepth(node1->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int main()
{
    int choice, Data, height;
    while (1)
    {
        printf("\nEnter choice of operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to add: ");
            scanf("%d", &Data);
            Insert(root, Data);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree is empty");
                break;
            }
            printf("Inorder traversal: ");
            Inorder(root);
            printf("\n");
            break;
        case 3:
            if (root == NULL)
            {
                printf("Tree is empty");
                break;
            }
            printf("Preorder traversal: ");
            Preorder(root);
            printf("\n");
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree is empty");
                break;
            }
            printf("Postorder traversal: ");
            Postorder(root);
            printf("\n");
            break;
        case 5:
            if (root == NULL)
            {
                printf("Tree is empty");
                break;
            }
            printf("Leaf nodes are: ");
            LeafNode(root);
            printf("\n");
            break;
        case 6:
            count = 0;
            CountNode(root);
            printf("Number of elements in tree is %d\n", count);
            break;
        case 7:
            Mirror(root);
            printf("Tree is inverted\n");
            break;
        case 8:
            height = maxDepth(root);
            printf("Height of tree is %d\n", height);
            break;
        case 9:
            return 0;
        default:
            printf("Enter proper option\n");
        }
    }
}