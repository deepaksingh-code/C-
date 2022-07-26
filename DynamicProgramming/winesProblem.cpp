#include<iostream>
using namespace std;
int wineProblem(int * arr,int left, int right, int year){
    if(left>right){
        return 0;
    }
    int option1=arr[left]*year + wineProblem(arr,left+1,right,year+1);
    int option2=arr[right]*year+ wineProblem(arr,left,right-1,year+1);
    return max(option1,option2);
}

int wineProblemDP(int* arr, int left, int right, int year,int** dp){
    if(left==right){
        return arr[left]*year;
    }
    if(dp[left][right]>-1){
        cout<<"time saved"<<endl;
        return dp[left][right];
    }
    int option1=arr[left]*year + wineProblem(arr,left+1,right,year+1);
    int option2=arr[right]*year+ wineProblem(arr,left,right-1,year+1);
    dp[left][right]=max(option1,option2);
    return max(option1,option2);
}
int main(){
    int n;
    cin>>n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ** dp= new int*[n];
    for(int i=0;i<n;i++){
        dp[i]= new int[n];
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<wineProblemDP(arr,0,n-1,0,dp)<<endl;
    cout<<wineProblem(arr,0,n-1, 1)<<endl;
    for(int i=0;i<n;i++)
        delete[] dp[i];
    delete[] dp;
    delete[] arr;
    return 0;
}