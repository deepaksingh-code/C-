#include<iostream>
using namespace std;


// input
// 9
// 0 1 5 8 9 10 17 17 20

//normal function
int rodCutting(int * arr, int n){
    int max=arr[n];
    int left=1;
    int right=n-1;
    while(left<=right){
        int firstProblem=rodCutting(arr,left);
        int secondProblem=rodCutting(arr,right);
        int total=firstProblem+secondProblem;
        if(total>max){
            max=total;
        }
        left++;
        right--;
    }
    return max;
}
// dynamic in top down
int rodCuttingTD(int * arr, int n,int* dp){
    int max=arr[n];
    int left=1;
    int right=n-1;
    if(dp[n]>-1){
        return dp[n];
    }
    while(left<=right){
        int firstProblem=rodCuttingTD(arr,left,dp);
        int secondProblem=rodCuttingTD(arr,right,dp);
        int total=firstProblem+secondProblem;
        if(total>max){
            max=total;
        }
        left++;
        right--;
    }
    dp[n]=max;
    return max;
}

int rodCuttingBU(int* arr,int n){

    if(n==0)
        return 0;
    int* dp= new int[n+1];
    dp[1]=arr[1];
    for(int i=2;i<n+1;i++){
        int max=arr[i];
        int left=1;
        int right=i-1;
        while(left<=right){
            cout<<left<<","<<right<<","<<max<<" ";
            int firstProblem= dp[left];
            int secondProblem=dp[right];
            int total=firstProblem+secondProblem;
            if(total>max){
                max=total;
            }
            left++;
            right--;
        }
        cout<<endl;
        dp[i]=max;
    }
    for(int i=1;i<n+1;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    int result=dp[n];
    delete[] dp;
    return result;
}
int main(){
    int n;
    cin>>n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int * dp= new int[n];
    for(int i=0;i<n;i++){
        dp[i]=-1;
    }
    cout<<"Maximum Profit is :"<<rodCuttingBU(arr,n-1)<<endl;
    cout<<"Maximum Profit is: "<<rodCuttingTD(arr,n-1,dp)<<endl;
    delete[] dp;
    cout<<"Maximum Profit is: "<<rodCutting(arr,n-1)<<endl;
    delete[] arr;
    return 0;
}