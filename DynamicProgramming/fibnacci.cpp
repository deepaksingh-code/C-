#include<iostream>
using namespace std;

//simple method
int fib(int n){
    if(n==1 or n==2){
        return 1;
    }
    else 
        return fib(n-1)+fib(n-2);
}

//Dynamic Aproach
int Fab(int *arr,int n){
    if (n==1||n==2){
        return 1;
    }
    if(arr[n]>0){
        return arr[n];
    }
    int output= Fab(arr,n-1)+Fab(arr,n-2);
    arr[n]=output;
    return output;
}

int main (){
    int n;

    cin>>n;

    //cout<<fib(n)<<endl;

    int * arr= new int(n+1);

    for(int i=0;i<n+1;i++){
        arr[i]=0;
    }
    cout<<Fab(arr,n)<<endl;
    return 0;
}