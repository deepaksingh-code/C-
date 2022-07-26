#include<iostream>
using namespace std;
// normal approach
int matrixChainMult(int* arr, int si, int ei){
    if(si+1==ei){
        return 0;
    }
    int min=INT8_MAX;
    for(int k=si+1;k<ei;k++){
        int firstProblem=matrixChainMult(arr,si,k);
        int secondProblem= matrixChainMult(arr,k,ei);
        int multOp=arr[si]*arr[k]*arr[ei];   //when multipy first and second then operation will be si*k*ei
        int total=multOp+firstProblem+secondProblem;
        if(total<min){
            min=total;                       // it will take min operation 
        }
    }
    return min;
}
// dynamic approach TOP DOWN APPROACH
int matrixChainMultDP(int* arr, int si, int ei, int ** dp){
    if(si+1==ei){
        return 0;
    }
    if(dp[si][ei]>-1){
        return dp[si][ei];
    }
    int min=INT8_MAX;
    for(int k=si+1;k<ei;k++){
        int firstProblem=matrixChainMult(arr,si,k);
        int secondProblem= matrixChainMult(arr,k,ei);
        int multOp=arr[si]*arr[k]*arr[ei];   //when multipy first and second then operation will be si*k*ei
        int total=multOp+firstProblem+secondProblem;
        if(total<min){
            min=total;                       // it will take min operations 
        }
    }
    dp[si][ei]=min;
    return min;

}
// bottom up approach
int matrixMultBU(int* arr,int n){

    int ** dp= new int*[n];
    for(int i=0;i<n;i++){
        dp[i]= new int[n];
    }
    for(int slide=1;slide<n;slide++){
        for(int si=0;si+slide<n;si++){
            int ei=si+slide;
            if(si+1==ei){
                dp[si][ei]=0;
            }
            else{
                int min=INT8_MAX;
                for(int k=si+1;k<ei;k++){
                    int firstProblem=dp[si][k];
                    int secondProblem=dp[k][ei];
                    int multOp=arr[si]*arr[k]*arr[ei];
                    int total=firstProblem+secondProblem+multOp;
                    if(total<min){
                        min=total;
                    }
                }   
                dp[si][ei]= min;
            }
        }
    }
    int minOperation=dp[0][n-1];
    for(int i=0;i<n;i++)
        delete[] dp[i];
    return minOperation;
}
 
int main(){
    int n;
    cin>>n;
    int* arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<matrixChainMult(arr,0,n-1)<<endl;
    int ** dp= new int*[n];
    for(int i=0;i<n;i++){
        dp[i]= new int[n];
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<"matrixChainMultDp :"<<matrixChainMultDP(arr,0,n-1,dp)<<endl;

    for(int i=0;i<n;i++)
        delete[] dp[i];
    delete[] arr;
    
    delete[] arr;
    return 0;
}