#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *front = NULL, *rear = NULL;
int isEmpty()
{
    return front == NULL;
}
struct node *createNode(struct node *tmp, int data)
{
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    tmp->info = data;
    return tmp;
}
void Enqueue(int data)
{
    struct node *tmp = createNode(tmp, data);
    if (isEmpty())
    {
        front = tmp;
        rear = tmp;
        tmp->link = NULL;
    }
    else
    {
        rear->link = tmp;
        rear = tmp;
        tmp->link = NULL;
    }
}
int peek()
{
    if (isEmpty())
    {
        printf("Queue is underflow!\n");
        exit(1);
    }
    return front->info;
}
int Dequeue()
{
    int item;
    struct node *tmp;
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    tmp = front;
    front = front->link;
    item = tmp->info;
    free(tmp);
    return item;
}
void display()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }
    struct node *p = front;
    printf("Queue contents are : \n");
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}
int main()
{
    int choice, item, deletedElement;
    printf(" (1) Enqueue item.\n");
    printf(" (2) Dequeue item.\n");
    printf(" (3) Peek.\n");
    printf(" (4) Display.\n");
    printf(" (5) Quit.\n");
    while (1)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter the item to be enqueued : ");
            scanf("%d", &item);
            Enqueue(item);
            printf("Element enqueued!\n");
            break;
        case 2:
            deletedElement = Dequeue();
            printf("The deleted element is %d\n", deletedElement);
            break;
        case 3:
            item = peek();
            printf("The front element is %d\n", item);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Enter valid choice!\n");
        }
    }
    return 0;
}