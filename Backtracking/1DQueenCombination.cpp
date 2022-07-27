#include<iostream>
using namespace std;


void queenCombination(bool* arr, int size, int qsfr,int q, string ans){
    if(qsfr==q){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<size;i++){
        if(arr[i]!=true){
            arr[i]=true;
            queenCombination(arr,size,qsfr+1,q,ans+'q'+to_string(qsfr)+'b'+to_string(i)+" ");
            arr[i]=false;
        }
    }
}
int main(){
    int n;
    cin>>n;
    bool* arr= new bool[n];
    string ans="";
    queenCombination(arr,n,0,2,ans);
    delete[] arr;
    return 0;
}