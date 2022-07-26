// Maximum square sum grid 

#include<iostream>
using namespace std;


//1,3,4    1,4,7                    0, 0 ,0
//2,3,5    3,9,17              ==>  0,1,4,7    
//2,4,5    5,15,28                  0,2,9,17
// input   expected dp array        0,5,15,28
//                                  programmed dp array
int maxSumGrid(int** arr, int n, int m){

    int** dp= new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i] = new int[m+1];   
    }
    //intialize first row with 0
    for(int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    //intialize first column with 0
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }

    // calculate dp array 
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            dp[i][j]= arr[i-1][j-1]+ dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1];
        }
    }

    //print dp array
    cout<<"DP array is: "<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // process for 2X2 grid
    int sum=INT16_MIN;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(i+1<n+1 && j+1<m+1){
                int s= dp[i+1][j]-dp[i+1][j-1]-dp[i-1][j+1]+dp[i-2][j-2];
                if (s>sum){
                    sum=s;
                }
            }
        }
    }


    return sum;
}
int main(){
    
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    cout<<"Enter an array: "<<endl;
    int** arr= new int*[n];
    for(int i=0;i<n;i++){
        arr[i]= new int[m];
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxSumGrid(arr,n,m)<<endl;
    return 0;
}