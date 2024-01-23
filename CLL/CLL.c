#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
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
    tmp->link = NULL;
    return tmp;
}
struct node *addtoEmpty(struct node *last, int data)
{
    struct node *tmp = createNode(data);
    last = tmp;
    last->link = last;
    return last;
}
struct node *addatBeg(struct node *last, int data)
{
    if (last == NULL)
    {
        last = addtoEmpty(last, data);
        return last;
    }
    struct node *tmp = createNode(data);
    tmp->link = last->link;
    last->link = tmp;
    return last;
}
struct node *addatEnd(struct node *last, int data)
{
    if (last == NULL)
    {
        last = addtoEmpty(last, data);
        return last;
    }
    struct node *tmp = createNode(data);
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}
struct node *createList(struct node *last)
{
    int data, size, i;
    printf("Enter the size of the list : ");
    scanf("%d", &size);
    if (size == 0)
    {
        printf("Empty list!\n");
        return last;
    }
    printf("Enter element : ");
    scanf("%d", &data);
    last = addtoEmpty(last, data);
    for (i = 2; i <= size; i++)
    {
        printf("Enter element : ");
        scanf("%d", &data);
        last = addatEnd(last, data);
    }
    printf("List created successfully!\n");
    return last;
}
struct node *deleteAlternateNodes(struct node *last)
{
    if (last == NULL)
    {
        prin琀昀("List is empty!\n");
        return last;
    }
    struct node *tmp, *p = last;
    if (last->link == last)
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    int 昀氀ag = 0;
    do
    {
        struct node *tmp = p->link;
        if (p->link == last)
        {
            last = p;
            昀氀ag = 1;
        }
        p->link = tmp->link;
        p = p->link;
        free(tmp);
    } while (p != last && 昀氀ag == 0);
    return last;
}
void *displayList(struct node *last)
{
    if (last == NULL)
    {
        prin琀昀("List is empty!\n");
        return last;
    }
    prin琀昀("List is : \n");
    struct node *p = last->link;
    do
    {
        prin琀昀("%d ", p->info);
        p = p->link;
    } while (p != last->link);
    prin琀昀("\n");
}
int main()
{
    struct node *last = NULL, *p;
    prin琀昀("Crea琀椀ng a list!\n");
    last = createList(last);
    prin琀昀("Displaying the created list : \n");
    displayList(last);
    prin琀昀("Dele琀椀ng the alternate nodes of the list(odd posi琀椀ons) : \n");
    last = deleteAlternateNodes(last);
    prin琀昀("Displaying the modi昀椀ed list : \n");
    displayList(last);
    return 0;
}