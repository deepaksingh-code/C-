// minimum step to 1
#include<iostream>
using namespace std;

//NORMAL APPROACH
int minStepTo1(int n){
    if(n<=1){
        return 0;
    }
    int option1=INT8_MAX;
    int option2=INT8_MAX;
    if(n%3==0){
        option1=1+minStepTo1(n/3);
    }
    if(n%2==0){
        option2=1+minStepTo1(n/2);
    }
    int option3= 1+minStepTo1(n-1);
    int ans= min(option1,min(option2,option3));
    return ans;
}
// dynamic approach
int minStepTo1DP(int n,int* dp){
    if(n<=1){
        return 0;
    }
    if(dp[n]>-1){
        return dp[n];
    }
    int option1=INT8_MAX;
    int option2=INT8_MAX;
    if(n%3==0){
        option1=1+minStepTo1(n/3);
    }
    if(n%2==0){
        option2=1+minStepTo1(n/2);
    }
    int option3= 1+minStepTo1(n-1);
    int ans= min(option1,min(option2,option3));
    dp[n]=ans;
    return ans;
}
// Bottom up approach

int minStep(int n){
    int* arr= new int[n+1];
    arr[0]=0;
    arr[1]=0;
    int option1=INT8_MAX;
    int option2=INT8_MAX;
    int option3;
    for(int i=2;i<n+1;i++){
        option1=INT8_MAX;
        option2=INT8_MAX;
        if(i%3==0){
            option1=arr[i/3];
        }
        if(i%2==0){
            option2=arr[i/2];
        }
        option3= arr[i-1];
        arr[i]=1+min(option1,min(option2,option3));
    }
    for(int i=0;i<n+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ans = arr[n];
    delete[] arr;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int * arr= new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    cout<<minStep(n)<<endl;
    cout<<minStepTo1DP(n,arr)<<endl;
    cout<<minStepTo1(n);
    delete[] arr;
    return 0;
}