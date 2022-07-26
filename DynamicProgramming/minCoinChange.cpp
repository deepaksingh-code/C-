#include<iostream>
using namespace std;

// normal approach
int minCoinChange(int* coins, int n, int money){
    if(money==0){
        return 0;
    }
    int ans=INT16_MAX;
    for(int i=0;i<n;i++){
        if(money-coins[i]>=0){
            ans= min(1+minCoinChange(coins,n,money-coins[i]),ans);
        }
    }
    return ans;
}
//using dp array
int minCoinChangeDP(int* coins, int n, int money,int* dp){
    if(money==0){
        return 0;
    }
    if(dp[money]>-1){
        return dp[money];
    }
    int ans=INT16_MAX;
    for(int i=0;i<n;i++){
        if(money-coins[i]>=0){
            ans= min(1+minCoinChangeDP(coins,n,money-coins[i],dp),ans);
        }
    }
    dp[money]=ans;
    return ans;
}

// bottom up approach
int minCoin(int* coins,int t, int n){
    int* dp= new int[n+1];
    dp[0]=0;
    for(int i=1;i<n+1;i++){
        int ans=INT16_MAX;
        for(int j=0;j<t;j++){
            if(i-coins[j]>=0){
                ans=min(1+dp[i-coins[j]],ans);
            }
        }
        dp[i]=ans;
    }
    int res=dp[n];
    delete[] dp;
    return res;
}


int main(){
    int n;
    cin>>n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    int* dp= new int[t+1];
    for(int i=0;i<t+1;i++){
        dp[i]=-1;
    }
    cout<<minCoin(arr,n,t)<<endl;
    cout<<minCoinChangeDP(arr,n,t,dp)<<endl;
    cout<<minCoinChange(arr,n,t)<<endl;
    delete[] dp;
    delete[] arr;
    return 0;
}