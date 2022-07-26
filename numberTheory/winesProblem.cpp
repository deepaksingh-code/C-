#include<iostream>
using namespace std;

int wineProblem(int * arr,int left, int right, int year){
    if(left>right){
        return 0;
    }
    int option1=arr[left]*year + wineProblem(arr,left+1,right,year+1);
    int option2=arr[right-1]*year+ wineProblem(arr,left,right-1,year+1);
    return max(option1,option2);
}

int main(){
    int n;
    cin>>n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<wineProblem(arr,0,n, 0)<<endl;
    delete[] arr;
    return 0;
}