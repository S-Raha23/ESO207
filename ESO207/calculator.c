#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100;
struct Stack{
    int size;
    int *arr;
    int top;
};

void Stack(struct Stack* ptr,int size){
    ptr->top=-1;
    ptr->size=size;
    ptr->arr = (int *)malloc(size * sizeof(int));
}
bool isEmpty(struct Stack* ptr){
    if(ptr->top==-1) return true;
    else return false;
}
void push(struct Stack* ptr,int val){
    
    if(ptr->top>=ptr->size-1) {
        printf("Overflowed\n");
        return;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
void pop(struct Stack* ptr){
    if(ptr->top==-1) printf("Underflowed");
    else{
        ptr->top--;
    }
}
int peek(struct Stack* ptr){
    if(ptr->top==-1) {
        printf("Empty");
        return 0;
    }
    return ptr->arr[ptr->top];
}
int size(struct Stack* ptr){
    return ptr->top+1;
}
int power(int a,int b){
    if(b==1) return a;
    if(b==0) return 1;
    int val=power(a,b/2);
    if(b%2==0) return val*val;
    else return val*val*a;
}
int find(char ope[],char c){
    for(int i=0;i<7;i++){
        if(ope[i]==c) return i;
    }
    return -1;
}

int main(){
    char str[100];
    scanf("%s",str);
    //char str[]="2+3*5";
    char ope[]={'-','+','*','/','^','(',')'};
    struct Stack num;
    struct Stack operator;
    Stack(&num,50);
    Stack(&operator,50);
    push(&operator,-10);
    int i=0;
    while(str[i]!='\0'){
        int val=0;
        bool flag=false;
        bool flag2=false;
        if(str[i]=='-' && peek(&operator)==-1){
            i++;
            flag2=true;
        }
        while(str[i]>='0' && str[i]<='9'){
            int digit=str[i]-'0';
            val=val*10+digit;
            flag=true;
            i++;
        }
        if(flag) {
            if(flag2) push(&num,val*-1);
            else push(&num,val);
            continue;
        }else{
        int op=find(ope,str[i]);
        if(op==6) op=-1;
        while(peek(&operator)>=op){
            int operation=peek(&operator);
            pop(&operator);
            if(operation==-1){
                op=6;
                continue;
            }
            int a=peek(&num);
            pop(&num);
            int b=peek(&num);
            pop(&num);
            if(operation==0) push(&num,b-a);
            else if(operation==1) push(&num,b+a);
            else if(operation==2) push(&num,b*a);
            else if(operation==3) push(&num,b/a);
            else if(operation==4) push(&num,power(b,a));
        }
        if(op==5) push(&operator,-1);
        else if(op==6) {
            i++;
            continue;
        }
        else push(&operator,op);
        i++;
        }
    }
    while(size(&num)>1){
        int a=peek(&num);
        pop(&num);
        int b=peek(&num);
        pop(&num);
        int operation=peek(&operator);
        pop(&operator);
        if(operation==0) push(&num,b-a);
        else if(operation==1) push(&num,b+a);
        else if(operation==2) push(&num,b*a);
        else if(operation==3) push(&num,b/a);
        else if(operation==4) push(&num,power(b,a));
    }
    printf("%d",peek(&num));
    
}