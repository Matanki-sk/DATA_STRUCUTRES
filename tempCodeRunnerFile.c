#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node* insert(int ele,struct node *tree){
    if(tree == NULL){
        tree = malloc(sizeof(struct node));
        tree->data = ele;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if(ele<tree->data){
        tree->left= insert(ele,tree->left);
    }
    else{
        tree->right= insert(ele,tree->right);
    }
    
    return tree;
}
struct node* findmin(struct node *t) {
    while (t->left != NULL) {
        t = t->left;
    }
    return t;
}

struct node* delete(int ele,struct node *t){
    struct node *temp;
    if(t == NULL){
        return NULL;
    }
    else{
        if(ele<t->data){
        t->left= delete(ele,t->left);
        }
        else if(ele<t->data){
            t->right= delete(ele,t->right);
        }
        else{
            if(t->left && t->right){
                temp = findmin(t->right);
                t->data = temp->data;
                t->right = delete(t->data,t->right);
            }
            else{
                temp = t;
                if(t->left == NULL){
                    t = t->right;
                }
                else if(t->right == NULL){
                    t = t->left;
                }
            }
            free(temp);
        }
        return t;
    }
}
void printBST(struct node *t) {
    if (t != NULL) {
        printBST(t->left);
        printf("%d ", t->data);
        printBST(t->right);
    }
}
int main(){
    int op,val;
    struct node * tree,*root;
    tree = malloc(sizeof(struct node*));
    printf("Enter the choice");
    scanf("%d",&op);
    if(op == 1){
        while (1) {
        printf("Enter element (or -1 to stop): ");
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        root = insert(val, root);
    }
    }
    else{
        delete(val,tree);
    }
    printBST(root);
    return 0;
}

