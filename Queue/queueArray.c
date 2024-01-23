#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1;
int rear = -1;
int cqueue[MAX];
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (front == 0 && rear == MAX - 1 || front == (rear + 1) % MAX)
        return 1;
    else
        return 0;
}
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    cqueue[rear] = item;
}
int dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    item = cqueue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX;
    return item;
}
int peek()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return cqueue[front];
}
void display()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    printf("Queue contents are : \n");
    int i = front;
    while (1)
    {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
int main()
{
    int choice, item;
    printf("MENU\n");
    printf(" (1) Enqueue\n");
    printf(" (2) Dequeue\n");
    printf(" (3) Display\n");
    printf(" (4) Peek\n");
    printf(" (5) Quit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            printf("Element removed is %d\n", item);
            break;
        case 3:
            display();
            break;
        case 4:
            item = peek();
            printf("The front element is %d\n", item);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid input!\n");
        }
    }
    return 0;
}