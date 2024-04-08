#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
struct stack{
    int data;
    struct stack *next;
}*top=NULL;
int main(){
    int ch;
    while(1){
        printf("\nEnter the operation to be done\n1.Push\n2.pop.\n3.quit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        /*case 2:
            pop();
            break;
        case 3:
            exit (0);
            break;*/
        default:
            printf("\nYou entered wrong choice");
            break;
        }
    }
    return 0;
}
void push(){
    struct stack *NN=malloc(sizeof(struct stack*));
    int data;
    printf("Enter the data to be inserted");
    scanf("%d",&data);
    if(top==NULL){
        top=NN;
    }
    else{
        top->next=NN;
        top=NN;
    }
    return;
}

/*void pop(){
    
}*/