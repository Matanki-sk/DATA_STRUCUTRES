#include <stdio.h>
void insertionsort(int a[],int size){
    for(int i = 0;i<size;i++){
        int key = a[i];
        int j = i-1;
        while(j>-1 && a[j]>key)
        {
          a[j+1]= a[j];
          j--;
        }
        a[j+1] = key;
    }
    for(int i =0 ;i<size;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[100];
    printf("Enter elements");
    for(int i = 0;i<5;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(a,5);
}