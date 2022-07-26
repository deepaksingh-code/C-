#include<iostream>
using namespace std;
bool subset(int* arr, int n, int sum){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    bool** dp= new bool*[2];
    for(int i=0;i<2;i++){
        dp[i]=new bool[sum+1];
    }
    for(int i=0;i<sum+1;i++){
        dp[0][i]=false;
    }
    dp[0][0]=true;

    int flag=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<sum+1;j++){
            dp[flag][j]=dp[flag^1][j];
            if(j>=arr[i-1])
                dp[flag][j]= dp[flag][j]||dp[flag^1][j-arr[i-1]];
        }
        flag=flag^1;
    }
    return dp[flag^1][sum];
}
    int n;
int main(){
    int n;
    cin>>n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<subset(arr,n,sum)<<endl;
    return 0;
}