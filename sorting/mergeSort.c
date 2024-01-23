#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* SortedMerge(struct Node *a, struct Node *b){
    struct Node *result = NULL;

    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    if(a->data <= b->data){
        result = a;
        result ->next = SortedMerge(a->next,b);
    }
}


int main(){

}