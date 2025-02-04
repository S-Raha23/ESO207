
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct queue {
    int size;
    int front;  // renamed from bottom
    int rear;   // renamed from top
    int *arr;
}queue;
typedef struct BST {
    int data;
    int frequency;
    struct BST* left;
    struct BST* right;
} BST;


// Initialize queue
void initQueue(queue* ptr, int size) {
    ptr->arr = (int*)malloc(size * sizeof(int));
    ptr->front = -1;
    ptr->rear = -1;
    ptr->size = size;
}

// Check if queue is empty
int isEmpty(queue* ptr) {
    return (ptr->front == -1 || ptr->front > ptr->rear);
}

// Check if queue is full
int isFull(queue* ptr) {
    return (ptr->rear == ptr->size - 1);
}

// Push element into queue
void pushInQueue(queue* ptr, int val) {
    if (isFull(ptr)) {
        printf("Queue Overflow\n");
        return;
    }
    if (ptr->front == -1) ptr->front = 0; // Set front when first element is added
    ptr->rear++;
    ptr->arr[ptr->rear] = val;
}

// Pop element from queue
int pop(queue* ptr) {
    if (isEmpty(ptr)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = ptr->arr[ptr->front];
    ptr->front++;
    return val;
}

int peek(queue* ptr){
    if (isEmpty(ptr)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return ptr->arr[ptr->front];
}
// Free allocated memory
void freeQueue(queue* ptr) {
    free(ptr->arr);
}

BST* newNode(int val) {
    BST* new = (BST*)malloc(sizeof(BST));
    if (!new) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = val;
    new->frequency = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void pushInBST(BST** root, int val) {
    if (*root == NULL) {
        *root = newNode(val);
        return;
    }

    BST* curr = *root;
    BST* prev = NULL;

    while (curr != NULL) {
        if (curr->data == val) {
            curr->frequency++;
            return;
        } else if (curr->data > val) {
            prev = curr;
            if (curr->left)
                curr = curr->left;
            else {
                prev->left = newNode(val);
                return;
            }
        } else {
            prev = curr;
            if (curr->right)
                curr = curr->right;
            else {
                prev->right = newNode(val);
                return;
            }
        }
    }
}


void function1(){
	//Write code for Q1
    
    
}
void preprocess(int** table,int arr[],int n,int col){
    for(int i=0;i<n;i++){
        table[i][0]=i;
    }
    for (int j = 1; (1 << j) <= n; j++) { 
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            int left = table[i][j - 1];
            int right = table[i + (1 << (j - 1))][j - 1];
            table[i][j] = (arr[left] < arr[right]) ? left : right;
        }
    }
   
}
void function2(){
    //Write code for Q2 
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int query[q][2];
    for(int i=0;i<q;i++){
        scanf("%d %d",&query[i][0],&query[i][1]);
    }
    printf("--------------------\n");
    int col=log2(n)+1;
    int **sparse_table= (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        sparse_table[i] = (int*)malloc(col * sizeof(int));
    }
    preprocess(sparse_table,arr,n,col);
    for(int i=0;i<q;i++){
        int l=query[i][0]-1;
        int r=query[i][1]-1;
        int j=log2(r-l+1);
        if(arr[sparse_table[l][j]]<arr[sparse_table[r+1-(1<<j)][j]]){
            printf("%d\n",arr[sparse_table[l][j]]);
        }else{
            printf("%d\n",arr[sparse_table[r+1-(1<<j)][j]]);
        }
    }
}
void function3(){
    //Write code for Q3
}
void function4(){
    //Write code for Q4
}

int main() {
    queue q;
    initQueue(&q, 10);  
    pushInQueue(&q, 15);
    pushInQueue(&q, 20);
    pushInQueue(&q, 25);
    pushInQueue(&q, 30);
    printf("%d\n", peek(&q)); 


    return 0;
}