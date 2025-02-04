#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    int frequency;
    struct BST* left;
    struct BST* right;
} BST;

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

void push(BST** root, int val) {
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

void pop(BST** root,int val){
    while(*root!=NULL){
        BST* node=*root;
        if(node->data==val){
            
        }
    }
}
void printBST(BST* root) {
    if (root == NULL) return;
    
    
    for (int i = 0; i < root->frequency; i++) {
        printf("%d\n", root->data);
    }
    printBST(root->left);
    printBST(root->right);
}

int main() {
    BST* root = NULL;
    push(&root, 15);
    push(&root, 10);
    push(&root, 1);
    push(&root, 12);
    push(&root, 20);
    push(&root, 25);
    push(&root, 22);
    push(&root, 20);
    push(&root, 20);
    
    printBST(root);
    return 0;
}
