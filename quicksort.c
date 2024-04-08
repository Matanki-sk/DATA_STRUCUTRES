#include <stdio.h>
void QuickSort(int arr[],int first,int last){
    int pivot,i=0,j=0,temp;
    if(first<last){
        pivot = first;
        i = first;
        j = last;
        while(i<j){
            while(arr[i]<arr[pivot] && i< last){
                i++;
            }
            while (arr[j]>arr[pivot]){
                j--;
            }
            if(i<j){
                temp = arr[i];
                arr[i]= arr[j];
                arr[j]=temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        QuickSort(arr,first,j-1);
        QuickSort(arr,j+1,last);
    }
}
int main(){
    int arr[10];
    printf("Enter the elements of the array");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,5);

    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}