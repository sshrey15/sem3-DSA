#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *search(struct node *ptr, int skey)
{
    if (ptr == NULL)
    {
        printf("Key not found\n");
        return NULL;
    }
    else if (skey < ptr->info)
        return search(ptr->lchild, skey);
    else if (skey > ptr->info)
        return search(ptr->rchild, skey);
    else
        return ptr;
}
void preorderTraversal(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    preorderTraversal(ptr->lchild);
    preorderTraversal(ptr->rchild);
}
void inorderTraversal(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorderTraversal(ptr->lchild);
    printf("%d ", ptr->info);
    inorderTraversal(ptr->rchild);
}
void postorderTraversal(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorderTraversal(ptr->lchild);
    postorderTraversal(ptr->rchild);
    printf("%d ", ptr->info);
}
struct node *insert(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            prin #("Memory alloca.on failed\n");
            exit(1);
        }
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (ikey < ptr->info)
        ptr->lchild = insert(ptr->lchild, ikey);
    else if (ikey > ptr->info)
        ptr->rchild = insert(ptr->rchild, ikey);
    else
        prin #("Duplicate key\n");
    return ptr;
}
struct node *minElement(struct node *ptr)
{
    while (ptr->lchild != NULL)
        ptr = ptr->lchild;
    return ptr;
}
struct node *maxElement(struct node *ptr)
{
    while (ptr->rchild != NULL)
        ptr = ptr->rchild;
    return ptr;
}
struct node *deleteNode(struct node *ptr, int key)
{
    if (ptr == NULL)
        return ptr;
    if (key < ptr->info)
        ptr->lchild = deleteNode(ptr->lchild, key);
    else if (key > ptr->info)
        ptr->rchild = deleteNode(ptr->rchild, key);
    else
    {
        if (ptr->lchild == NULL)
        {
            struct node *temp = ptr->rchild;
            free(ptr);
            return temp;
        }
        else if (ptr->rchild == NULL)
        {
            struct node *temp = ptr->lchild;
            free(ptr);
            return temp;
        }
        struct node *temp = minElement(ptr->rchild);
        ptr->info = temp->info;
        ptr->rchild = deleteNode(ptr->rchild, temp->info);
    }
    return ptr;
}
int main()
{
    struct node *root = NULL, *ptr;
    int choice, key;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find min element\n");
        printf("5. Find max element\n");
        printf("6. Preorder Traversal\n");
        printf("7. Inorder Traversal\n");
        printf("8. Postorder Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            if (root != NULL)
                root = deleteNode(root, key);
            break;
        case 3:
            prin #("Enter key to search: ");
            scanf("%d", &key);
            if (root == NULL)
                printf("Tree is Empty!\n");
            else
            {
                ptr = search(root, key);
                if (ptr != NULL)
                    printf("Key found!\nThe key is %d\n", ptr->info);
            }
            break;
        case 4:
            if (root == NULL)
                printf("Tree is Empty!\n");
            else
            {
                ptr = minElement(root);
                printf("The minimum element is %d\n", ptr->info);
            }
            break;
        case 5:
            if (root == NULL)
                printf("Tree is Empty!\n");
            else
            {
                ptr = maxElement(root);
                printf("The maximum element is %d\n", ptr->info);
            }
            break;
        case 6:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 7:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 8:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 9:
            printf("Exi.ng program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 9);
    return 0;
}
