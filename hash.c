#include <stdio.h>
#include<stdlib.h>
void insert(int);
void delete(int);
void search(int);
void print();
# define SIZE 10
int hashtable[SIZE];
int main(){
    int val , op= 0;
    for(int i = 0;i<SIZE ; i++){
        hashtable[i]=-1;
    }
    while (1)
    {
        printf("Enter the option \n 1.Insert\n2.Delete\n3.search\n4.print\n5.exit\n");
        scanf("%d",&op);
       switch (op)
       {
        case 1:
            printf("Enter element to be inserted\n");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            printf("Enter element to be deleted\n");
            scanf("%d",&val);
            delete(val);
            break;
        case 3:
            printf("Enter element to be searched\n");
            scanf("%d",&val);
            search(val);
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);
       default:
            printf("Invalid option\n");
            break;
       }
    }
    return 0;
}
void insert(int val){
    int key = val % SIZE;
    if(hashtable[key]==-1){
        hashtable[key] = val;
        printf("Element inserte successully\n");
    }
    else{
        printf("Collision occured\n");
    }
}
void delete(int val){
    int key = val % SIZE;
    if(hashtable[key]==val){
        hashtable[key]= -1;
        printf("Element deleted\n");
    }
    else{
        printf("Element not found\n");
    }
}
void search(int val){
    int key = val % SIZE;
    if(hashtable[key]==val){
        printf("Element Found\n");
    }
    else{
        printf("Element not found\n");
    }
}
void print(){
    for(int i = 0;i<SIZE;i++){
        if(hashtable[i]!=-1){
            printf("[%d]=>%d",i,hashtable[i]);
        }
        if(i>=SIZE){
            break;
        }
    }
}
