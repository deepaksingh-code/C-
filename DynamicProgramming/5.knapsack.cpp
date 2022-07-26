#include<iostream>
using namespace std;

//normal approach
int knapsack(int W,int* w,int *p,int n){
    if(W==0||n==0){
        return 0;
    }
    int takeit=INT16_MIN;
    if(w[n-1]<=W)
        takeit=p[n-1]+knapsack(W-w[n-1],w,p,n-1);
    int donottakeit=knapsack(W,w,p,n-1);
    return max(takeit,donottakeit);
}

// Dynamic approach



int main(){
    int n,W;
    cout<<"Enter n and W: ";
    cin>>n>>W;
    int * p = new int[n];
    int * w = new int[n];
    cout<<"Enter weights: ";
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cout<<"Enter Profits: ";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    cout<<"Knapsack is: "<<knapsack(W,w,p,n)<<endl;

    return 0;
}