#include<iostream>
using namespace std;

//check string partition is palindrom or not
bool isPalindromString(string s, int si, int ei){
    int l=si;
    int r=ei;
    while(l<=r){
        if(s[l]!=s[r]){
            return false;
        }    
    }
    return true;
}
// recursive way to find palindrom
int palindromPartition(string s, int si, int ei){
    if(isPalindromString(s,si,ei)){
        return 0;
    }
    int min=INT8_MAX;
    for(int k=si;k<ei;k++){
        int fp=palindromPartition(s,si,k);
        int sp=palindromPartition(s,k+1,ei);
        int total=fp+sp+1;
        if(min<total)
            min =total;
    }
    return min;
}
int main(){
    string s;
    cin>>s;
    cout<<"Minimum cut is: "<<palindromPartition(s,0,s.length()-1)<<endl;

    return 0;
}