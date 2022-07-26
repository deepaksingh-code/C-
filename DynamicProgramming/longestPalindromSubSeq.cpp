#include<iostream>
using namespace std;

int longestPalindromicSubSequence(string s, int si, int ei){
    if(si>ei)
        return 0;
    if(si==ei){
        return 1;
    }
    if(s[si]==s[ei]){
        return longestPalindromicSubSequence(s,si+1,ei-1)+2;
    }
    int removeFirstChar=longestPalindromicSubSequence(s,si+1,ei);
    int removeLastChar=longestPalindromicSubSequence(s,si,ei-1);
    return max(removeFirstChar,removeLastChar);
}
int main(){
    string s;
    cin>>s;
    cout<<"longest palindrom is: "<<longestPalindromicSubSequence(s,0,s.length()-1)<<endl;
    return 0;
}