#include <stdio.h>
#include <stdlib.h>
#define MAX 15
struct node *queue[MAX];
int front = -1, rear = -1;
int isEmpty()
{
    return front == -1 || front == rear + 1;
}
void insertQueue(struct node *item)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = item;
}
struct node *delQueue()
{
    struct node *item;
    if (front == -1 || front == rear + 1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    item = queue[front];
    front = front + 1;
    return item;
}
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *createNode(int info)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = info;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    return tmp;
}
struct node *construct(int inorder[], int start, int end, int postorder[], int *pIndex)
{
    if (start > end)
    {
        return NULL;
    }
    struct node *tmp = createNode(postorder[(*pIndex)--]);
    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == tmp->info)
        {
            break;
        }
    }
    tmp->rchild = construct(inorder, i + 1, end, postorder, pIndex);
    tmp->lchild = construct(inorder, start, i - 1, postorder, pIndex);
    return tmp;
}
struct Node *constructTree(int inorder[], int postorder[], int n)
{
    int *pIndex = &n;
    return construct(inorder, 0, n, postorder, pIndex);
}
int heightofTree(struct node *ptr)
{
    if (ptr == NULL)
        return 0;
    int lchildsubtreeH = heightofTree(ptr->lchild);
    int rchildsubtreeH = heightofTree(ptr->rchild);
    int maxHeight = (lchildsubtreeH >= rchildsubtreeH) ? lchildsubtreeH : rchildsubtreeH;
    return maxHeight + 1;
}
void preorderTraversal(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    preorderTraversal(ptr->lchild);
    preorderTraversal(ptr->rchild);
}
void levelorderTraversal(struct node *root)
{
    struct node *ptr = root;
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    insertQueue(ptr);
    while (!isEmpty())
    {
        ptr = delQueue();
        printf("%d ", ptr->info);
        if (ptr->lchild != NULL)
            insertQueue(ptr->lchild);
        if (ptr->rchild != NULL)
            insertQueue(ptr->rchild);
    }
    printf("\n");
}
int findDepth(struct node *root, int key, int depth)
{
    if (root == NULL)
        return -1;
    if (root->info == key)
        return depth;
    int leftDepth = findDepth(root->lchild, key, depth + 1);
    if (leftDepth != -1)
        return leftDepth;
    int rightDepth = findDepth(root->rchild, key, depth + 1);
    return rightDepth;
}
int main()
{
    struct node *root = NULL;
    int size, i;
    printf("Enter the number of nodes in the tree : ");
    scanf("%d", &size);
    int inorder[size], postorder[size];
    printf("Enter the keys in inorder : ");
    for (i = 0; i < size; i++)
        scanf("%d", &inorder[i]);
    printf("Enter the keys in postorder : ");
    for (i = 0; i < size; i++)
        scanf("%d", &postorder[i]);
    root = constructTree(inorder, postorder, size - 1);
    int choice;
    int key, depth;
    do
    {
        printf("\nBinary Tree Operations:\n");
        printf("1. Preorder Traversal\n");
        printf("2. Height of the Tree\n");
        printf("3. Level Order Traversal\n");
        printf("4. Find Depth of a Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 2:
            printf("The height of the tree is %d\n", heightofTree(root));
            break;
        case 3:
            printf("Level Order Traversal: ");
            levelorderTraversal(root);
            break;
        case 4:
            printf("Enter the element to find its depth: ");
            scanf("%d", &key);
            depth = findDepth(root, key, 0);
            if (depth != -1)
            {
                printf("The depth of node with key %d is %d\n", key, depth);
            }
            else
            {
                printf("Node with key %d not found in the tree.\n", key);
            }
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
    return 0;
}