#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool * arr= new bool[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++){
        if(arr[i]==true){
            for(int j=i;j<=n;j=j+i){
                arr[j]=false;      
            }
        }
    }
    int count=0;
    for(int i=0;i<n+1;i++){
        if(arr[i]==true){
            count++;
        }
    }
    cout<<count;

    delete[] arr;
    return 0;
}