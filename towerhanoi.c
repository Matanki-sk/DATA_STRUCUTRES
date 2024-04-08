#include<stdio.h>
void towerOfHanoi(int n,char source,char destination,char auxilary){
    if(n==1){
        printf("move disk 1 from %c to %c\n",source,destination);
        return;
    }
    towerOfHanoi(n-1,source,destination,auxilary);
    printf("move disk %d from %c to %c\n",n,source,destination);
    towerOfHanoi(n-1,auxilary,source,destination);
}
int main(){
    int n;
    printf("Enter the number of disks");
    scanf("%d",&n);
    towerOfHanoi(n,'A','B','C');
}