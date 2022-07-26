#include<iostream>
using namespace std;
int numOfBinTree(int n){
    int total=0;
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    for(int i=1;i<=n;i++){
        int leftBST= numOfBinTree(i-1);
        int rightBST= numOfBinTree(n-i);
        int numofBSTwitRoot= leftBST*rightBST;
        total+=numofBSTwitRoot;
    }
    return total;
}
int main(){
    int n;
    cin>>n;
    cout<<"number of binary tree: "<<numOfBinTree(n)<<endl;    
    return 0;
}