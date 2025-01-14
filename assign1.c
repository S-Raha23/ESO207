#include<stdio.h>

int max(long int a,long int b){
    return (a>b)?a:b;
}

int min(long int a,long int b){
    return (a>b)?b:a;
}
int RFib(int n){
    if(n<=1) return n;
    return (RFib(n-1)+RFib(n-2))%2025;
}

void multiply(int arr1[2][2],int arr2[2][2]){
    int res[2][2];
    res[0][0]=(arr1[0][0]*arr2[0][0])+(arr1[0][1]*arr2[1][0]);
    res[0][1]=(arr1[0][0]*arr2[0][1])+(arr1[0][1]*arr2[1][1]);
    res[1][0]=(arr1[1][0]*arr2[0][0])+(arr1[1][1]*arr2[1][0]);
    res[1][1]=(arr1[1][0]*arr2[0][1])+(arr1[1][1]*arr2[1][1]);

    arr1[0][0]=res[0][0];
    arr1[0][1]=res[0][1];
    arr1[1][0]=res[1][0];
    arr1[1][1]=res[1][1];
}

void PowerOf(int arr[2][2],int n){
    if(n==1) return;
    int first[2][2]={{1,1},{1,0}};
    PowerOf(arr,n/2);
    if(n%2==0){
        multiply(arr,arr);
    }else{
        multiply(arr,arr);
        multiply(arr,first);
    }
}
int CleverFib(long int n){
    if(n<=1) return n;
    int arr[2][2]={{1,1},{1,0}};
    PowerOf(arr,n-1);
    return (arr[0][0])%2025;
}

int TrivialGCD(int a, int b){
    int mini=min(a,b);
    for(int i=mini;i>=1;i--){
        if(b%i==0 && a%i==0){
            return i;
        }
    }
}

long int EuclidGCD(long int a, long int b){
    long int high=max(a,b),low=min(a,b);
    long int remainder=high%low;
    while(remainder!=0){
        high=low;
        low=remainder;
        remainder=high%low;
    }
    return low;
}




