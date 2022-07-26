#include<iostream>
#include<string>
using namespace std;

//s1='deepak'
//s2='adpak'

//normal approach
int lcs(string s1,string s2,int m,int n){
    if(m==0||n==0){
        return 0;
    }
    if(s1[0]==s2[0]){
        return 1+lcs(s1.substr(1),s2.substr(1),m-1,n-1);
    }
    
    int option1= lcs(s1.substr(1),s2,m-1,n);
    int option2= lcs(s1,s2.substr(1),m,n-1);

    return max(option1,option2);
}
//dynamic approach
int LCS(string s1,string s2,int m, int n, int** dp){
    if(m==0||n==0){
        return 0;
    }
    if(dp[m][n]>0){
        return dp[m][n];
    }
    int option1= lcs(s1.substr(1),s2,m-1,n);
    int option2= lcs(s1,s2.substr(1),m,n-1);

    int maximum=max(option1,option2);
    dp[m][n]=maximum;
    return maximum;
}
//Iterative approach 
int lcsIterative(string s1,string s2,int m, int n){
    int** output= new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n+1];
    }
    for(int i=0;i<m+1;i++){
        output[i][0]=0;
    }
    for(int i=0;i<n+1;i++){
        output[0][i]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s1[i-1]==s2[j-1]){
                output[i][j]=1+output[i-1][j-1];
            }
            else{
                output[i][j]=max(output[i-1][j],output[i][j-1]);
            }
        }
    }
    int maximum=output[m+1][n+1];
    for(int i=0;i<m+1;i++){
        delete[] output[i];
    }
    delete[] output;
    return maximum;
}

int main(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int m=s1.length();
    int n=s2.length();  
    int** output= new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }
    cout<<"output array created and intialized"<<endl;
    cout<<"Recursive Dynamic: "<<LCS(s1,s2,m-1,n-1,output)<<endl;
    // for(int i=0;i<n;i++){
    //     delete[] output[i];
    // }
    // delete[] output;
   // cout<<"Iterative approach: "<<lcsIterative(s1,s2,m,n)<<endl;
    cout<<"Normal Recursive Approach: "<<lcs(s1,s2,m,n)<<endl;
    return 0;
}