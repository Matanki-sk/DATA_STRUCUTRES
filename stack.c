#include<stdio.h>
#include<stdlib.h>
#define Max 5 
int stack[Max];
int top=-1;
void push();
void pop();
void viewtop();
void printStack();
int main(){
    int ch;
    while(1){
        printf("\nEnter the operation to be done\n1.Push\n2.pop.\n3.view top element\n4.view stack\n5.quit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            viewtop();
            break;
        case 4:
            printStack();
            break;
        case 5:
            exit (0);
            break;
        default:
            printf("\nYou entered wrong choice");
            break;
        }
    }
    return 0;
}
void push(){
    int data;
    printf("\nEnter the data to insert");
    scanf("%d",&data);
    if(top==Max-1){
        printf("\nStack Overflow");
        return ;
    }
    top++;
    stack[top]=data;
    printf("\nData inserted");
}
void pop(){
    int temp;
    if(top==-1){
        printf("\nStack underflow");
        return;
    }
    temp=stack[top];
    top--;
    printf("%d element Popped sucessfully",temp);
}
void viewtop(){
    if(top==-1){
        printf("\nStack underflow");
        printf("\nThe top element is %d",stack[top]);
        return;
    }
    if(top==Max-1){
        printf("\nStack Overflow");
        printf("\nThe top element is %d",stack[top]);
        return;
    }
    printf("\nThe top element is %d",stack[top]);
}
void printStack(){
    for(int i=0;i<=top;i++){
        printf("%d",stack[i]);
    }
    return;
}

