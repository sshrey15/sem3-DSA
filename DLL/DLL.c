#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}
struct node *addAtBeg(struct node *start, int data)
{
    struct node *tmp = createNode(data);
    if (start == NULL)
    {
        start = tmp;
        return start;
    }
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}
struct node *addAtEnd(struct node *start, int data)
{

    struct node *tmp = createNode(data);
    if (start == NULL)
    {
        start = tmp;
        return start;
    }
    struct node *p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->prev = p;
    return start;
}
struct node *createList(struct node *start)
{
    int size, i, data;
    printf("Enter number of terms to be created : ");
    scanf("%d", &size);
    if (size == 0)
        return start;
    printf("Enter element : ");
    scanf("%d", &data);
    start = addAtBeg(start, data);
    for (i = 2; i <= size; i++)
    {
        printf("Enter element : ");
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }
    return start;
}
void displayList(struct node *start)
{
    if (start == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct node *p = start;
    printf("List is : \n");
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}
struct node *swapAdjacent(struct node *start)
{
    if (start == NULL)
    {
        printf("List is Empty!\n");
        return start;
    }
    struct node *p = start, *q;
    while (p != NULL)
    {
        q = p->next;
        if (p->prev == NULL)
            start = q;
        if (q != NULL)
        {
            p->next = q->next;
            q->prev = p->prev;
            if (p->prev != NULL)
                p->prev->next = q;
            p->prev = q;
            if (q->next != NULL)
                p->next->prev = p;
            q->next = p;
            p = p->next;
        }
        else
            break;
    }
    printf("Adjacent elements swapped successfully!\n");
    return start;
}
struct node *reverseList(struct node *start)
{
    struct node *p, *q;
    p = start;
    q = p->next;
    p->next = NULL;
    p->prev = q;
    while (q != NULL)
    {
        q->prev = q->next;
        q->next = p;
        p = q;
        q = q->prev;
    }
    start = p;
    printf("List reversed successfully!\n");
    return start;
}
struct node *numberToList(struct node *start, int num)
{
    int digit;
    while (num > 0)
    {
        digit = num % 10;
        start = addAtEnd(start, digit);
        num /= 10;
    }
    return start;
}
struct node *addNumbers(struct node *start1, struct node *start2)
{
    struct node *start3 = NULL;
    struct node *p, *q;
    if (listLength(start1) >= listLength(start2))
    {
        p = start1;
        q = start2;
    }
    else
    {
        p = start2;
        q = start1;
    }
    int carry = 0, sum = 0, digit;
    while (q != NULL)
    {
        sum = carry + p->info + q->info;
        digit = sum % 10;
        start3 = addAtEnd(start3, digit);
        carry = sum / 10;
        p = p->next;
        q = q->next;
    }
    while (p != NULL)
    {
        sum = carry + p->info;
        digit = sum % 10;
        start3 = addAtEnd(start3, digit);
        carry = sum / 10;
        p = p->next;
    }
    printf("Numbers added successfully!\n");
    return start3;
}
int main()
{
    struct node *start = NULL, *start1 = NULL, *start2 = NULL, *result = NULL;
    int choice, num1, num2;
    while (1)
    {
        printf("\t(1) Create List.\n");
        printf("\t(2) Display List.\n");
        printf("\t(3) Swap adjacent elements.\n");
        printf("\t(4) Reverse List.\n");
        printf("\t(5) Add two numbers.\n");
        printf("\t(6) Quit.\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = createList(start);
            break;
        case 2:
            displayList(start);
            break;
        case 3:
            start = swapAdjacent(start);
            break;
        case 4:
            start = reverseList(start);
            break;
        case 5:
            printf("Enter the first number : ");
            scanf("%d", &num1);
            printf("Enter the second number : ");
            scanf("%d", &num2);
            start1 = numberToList(start1, num1);
            printf("Start1 : \n");
            displayList(start1);
            start2 = numberToList(start2, num2);
            printf("Start2 : \n");
            displayList(start2);
            result = addNumbers(start1, start2);
            result = reverseList(result);
            printf("The sum of %d and %d is : \n", num1, num2);
            displayList(result);
            break;
        case 6:
            exit(0);
        default:
            printf("Enter valid choice.\n");
        }
    }
    return 0;
}