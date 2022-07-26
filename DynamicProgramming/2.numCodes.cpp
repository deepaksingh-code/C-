#include<iostream>

using namespace std;

int numCode(int * arr, int n){
    if(n==0||n==1){
        return 1;
    }
    int output=numCode(arr,n-1);
    if((arr[n-1]*10+arr[n-2])<=26){
        output+=numCode(arr,n-2);
    }  
    return output;
}

int main(){
    int n;
    int* arr= new int(n);
    for(int i=n-1;i>=0;i--){
        cin>>arr[i];
    }
    cout<<numCode(arr,n)<<endl;

}
