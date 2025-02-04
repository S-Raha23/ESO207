#include<stdio.h>
#include<math.h>

void preprocess(int arr[],int n){
    int col=log2(n);
    int lookup[n][col];
    for(int i=0;i<n;i++){
        lookup[i][0]=i;
    }    
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;(i+(1<<j)-1)<n;i++){
            if (arr[lookup[i][j - 1]]
                < arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j]
                    = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

void RMQ(int arr[],int n){
    preprocess(arr,n);
}

int main(){
    int arr[]={ 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int size=sizeof(arr)/sizeof(arr[0]);
    int query[3][2]={ { 0, 4 }, { 4, 7 }, { 7, 8 } };
}