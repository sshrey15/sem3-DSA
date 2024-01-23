#include<stdio.h>
#define MAX 10

int cqueue_arr[MAX];
int front = -1;
int rear =-1;



int isEmpty(){
    if(front == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    return (front == 0 && rear == MAX-1) || (front == (rear+1)%MAX);

}

void insert(int item)
{
    if(isFull()){
        printf("Queue overflow\n");
        return ;
    }
    item = cqueue_arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front + 1)%MAX;
        return item;
    }
}

int del(){
    int item;
    if(isEmpty()){
        printf("queue underflow\n");

    }
    item = cqueue_arr[front];
    if(front ==  rear){
        front = -1;
        rear  =-1;
    }else{
        front = (front+1)%MAX;
        return item;
    }
}

void display(){
    int i;
    if(isEmpty()){
        printf("queue is empty\n");
        return;
    }
    printf("queue is:\n\n");
    i=front;
    while(1){
        printf("%d",cqueue_arr[i]);
        if(i==rear)
        break;
        i = (i+1)%MAX;

    }
    printf("\n");
}

int peek(){
    if(isEmpty()){
        printf("queue underflow\n");
    }
    return cqueue_arr[front];
}
int main(){
    int choice, item;
    front = -1;
    rear = -1;  

    while(1){
        printf("\nMenu\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Peek\n");
        printf("5.Quit\n");

        printf("enter your choice: \n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("enter the item to be inserted: ");
                scanf("%d",&item);
                break;

            case 2:
                item = del();
                printf("the deleted item is %d",item);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("fornt element is %d",peek());
                break;

            case 5:
                exit(0);
                break;
            default:
                printf("invalid choie");
                break;
        }
    }

    return 0;
}