#include<stdio.h>

void insertionSort(int arr[],int n){
    int i,key,j;
    for(i=1; i<n; i++){
        arr[i] = key;
        j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j =j-1;
        }

        arr[j+1] = key;
    }

}

int printArray(int arr[],int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d",arr[i]);

    }
    printf("\n");
}

int main(){
    int arr[] = {12,34,54,45,45};
    int n = sizeof(arr)/ sizeof(arr[0]);

    intsertionSort(arr,n);
    printdArray(arr,n);
    return 0;
}