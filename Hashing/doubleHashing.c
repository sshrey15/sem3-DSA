#include <stdio.h>
#include <stdlib.h>
#define MAX 11
enum type_of_record
{
    EMPTY,
    DELETED,
    OCCUPIED
};
struct employee
{
    int empid;
    char name[20];
    int age;
};
struct Record
{
    struct employee info;
    enum type_of_record status;
};
void insert(struct employee emprec, struct Record table[]);
int search(int key, struct Record table[]);
void del(int key, struct Record table[]);
void display(struct Record table[]);
int doubleHash(int key);
int hash(int key);
int main()
{
    struct Record table[MAX];
    struct employee emprec;
    int i, key, choice;
    for (i = 0; i <= MAX - 1; i++)
        table[i].status = EMPTY;
    printf("1. Insert a record\n");
    printf("2. Search a record\n");
    printf("3. Delete a record\n");
    printf("4. Display table\n");
    printf("5. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter empid, name, age : ");
            scanf("%d%s%d", &emprec.empid, emprec.name, &emprec.age);
            insert(emprec, table);
            break;
        case 2:
            printf("Enter a key to be searched : ");
            scanf("%d", &key);
            i = search(key, table);
            if (i == -1)
                printf("Key not found\n");
            else
                printf("Key found at index %d\n", i);
            break;
        case 3:
            printf("Enter a key to be deleted\n");
            scanf("%d", &key);
            del(key, table);
            break;
        case 4:
            display(table);
            break;
        case 5:
            exit(1);
        }
    }
}
int doubleHash(int key)
{
   return (7 + (key%(MAX-7)));
}
int hash(int key)
{
    return (key%MAX);
}
void insert(struct employee emprec, struct Record table[])
{
    int i, location, h, h2;
    int key = emprec.empid;
    h = hash(key);
    h2 = doubleHash(key);
    location = h;
    for (i = 1; i <= MAX - 1; i++)
    {
        if (table[location].status == EMPTY || table[location].status == DELETED)
        {
            table[location].info = emprec;
            table[location].status = OCCUPIED;
            printf("Record inserted\n\n");
            return;
        }
        if (table[location].info.empid == key )
        {
            printf("Duplicate key\n\n");
            return;
        }
        location = (h + i * h2) % MAX;
    }
    printf("Record can't be inserted : Table overFlow\n\n");
}
int search(int key, struct Record table[])
{
    int i, h, h2, location;
    h = hash(key);
    h2 = doubleHash(key);
    location = h;
    for (i = 1; i <= MAX - 1; i++)
    {
        if (table[location].status == EMPTY)
            return -1;
        if (table[location].info.empid == key && table[location].status == OCCUPIED)
            return location;
        location = (h + i * h2) % MAX;
    }
    return -1;
}
void del(int key, struct Record table[])
{
    int location = search(key, table);
    if (location == -1)
        printf("Key not found\n");
    else
        table[location].status = DELETED;
}
void display(struct Record table[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("[%d] : ", i);
        if (table[i].status == OCCUPIED)
        {
            printf("Occupied : %d %s", table[i].info.empid, table[i].info.name);
            printf(" %d\n", table[i].info.age);
        }
        else if (table[i].status == DELETED)
            printf("Deleted\n");
        else
            printf("Empty\n");
    }
}