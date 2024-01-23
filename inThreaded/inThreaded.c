#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    False,
    True
} boolean;

struct node
{
    struct node *left;
    boolean lthread;
    int info;
    boolean rthread;
    struct node *right;
};

struct node *in_succ(struct node *ptr)
{
    if (ptr->rthread == True)
        return ptr->right;
    else
    {
        ptr = ptr->right;
        while (ptr->lthread == False)
            ptr = ptr->left;
        return ptr;
    }
}

struct node *in_pred(struct node *ptr)
{
    if (ptr->lthread == True)
        return ptr->left;
    else
    {
        ptr = ptr->left;
        while (ptr->rthread == False)
            ptr = ptr->right;
        return ptr;
    }
}

void inorder(struct node *root)
{
    struct node *ptr;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr = root;
    while (ptr->lthread == False)
        ptr = ptr->left;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = in_succ(ptr);
    }
}

void preorder(struct node *root)
{
    struct node *ptr;
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    ptr = root;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        if (ptr->lthread == False)
            ptr = ptr->left;
        else if (ptr->rthread == False)
            ptr = ptr->right;
        else
        {
            while (ptr != NULL && ptr->rthread == True)
                ptr = ptr->right;
            if (ptr != NULL)
                ptr = ptr->right;
        }
    }
}

struct node *insert(struct node *root, int ikey)
{
    struct node *tmp, *ptr, *par;
    boolean found = False;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = ikey;
    tmp->lthread = True;
    tmp->rthread = True;
    if (root == NULL)
    {
        tmp->left = NULL;
        tmp->right = NULL;
        root = tmp;
        return root;
    }
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
        if (ikey == ptr->info)
        {
            printf("Duplicate key\n");
            free(tmp);
            return root;
        }
        if (ikey < ptr->info)
        {
            if (ptr->lthread == False)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == False)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (ikey < par->info)
    {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = False;
        par->left = tmp;
    }
    else
    {
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = False;
        par->right = tmp;
    }
    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    struct node *ptr, *par;
    boolean found = False;
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (key == ptr->info)
        {
            found = True;
            break;
        }
        par = ptr;
        if (key < ptr->info)
        {
            if (ptr->lthread == False)
            {
                ptr = ptr->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (ptr->rthread == False)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }
    }
    if (!found)
    {
        printf("Key not found\n");
        return root;
    }
    if (ptr->lthread == True && ptr->rthread == True)
    {
        if (par == NULL)
        {
            free(ptr);
            root = NULL;
        }
        else if (ptr == par->left)
        {
            par->lthread = True;
            par->left = ptr->left;
            free(ptr);
        }
        else
        {
            par->rthread = True;
            par->right = ptr->right;
            free(ptr);
        }
    }
    else if (ptr->lthread == False || ptr->rthread == False)
    {
        if (ptr->lthread == False)
        {
            struct node *pred = in_pred(ptr);
            int tmp = ptr->info;
            ptr->info = pred->info;
            pred->info = tmp;
            root = deleteNode(root, pred->info);
        }
        else
        {
            struct node *succ = in_succ(ptr);
            int tmp = ptr->info;
            ptr->info = succ->info;
            root = deleteNode(root, succ->info);
        }
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    struct node *ptr = root;
    while (ptr != NULL)
    {
        if (key == ptr->info)
            return ptr;
        else if (key < ptr->info)
        {
            if (ptr->lthread == False)
                ptr = ptr->left;
            else
                return NULL;
        }
        else
        {
            if (ptr->rthread == False)
                ptr = ptr->right;
            else
                return NULL;
        }
    }
    return NULL;
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
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Search key\n");
        printf("6. Exit\n");
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
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the key you want to search: ");
            scanf("%d", &key);
            ptr = search(root, key);
            if (ptr == NULL)
                printf("Element not found!\n");
            else
                printf("Element found!\nElement is %d\n", ptr->info);
            break;
        case 6:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}