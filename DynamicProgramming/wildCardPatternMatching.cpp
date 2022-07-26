#include<iostream>
using namespace std;

bool wildCardPatternMatching(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    if(n==0&&m==0){
        return true;
    }
    if(m==0){
        return false;
    }
   if(text[0]==pattern[0]||pattern[0]=='?'){
       return wildCardPatternMatching(text.substr(1),pattern.substr(1));
   }
   if(pattern[0]=='*'){
       return wildCardPatternMatching(text,pattern.substr(1)) ||  wildCardPatternMatching(text.substr(1),pattern);
   }
   if(text[0]!=pattern[0]){
       return false;
   }
}

//bool wildCardPatternMatching(string text)

int main(){
    string text;
    string pattern;
    cin>>text;
    cin>>pattern;
    cout<<"is pattern matched with text: "<<wildCardPatternMatching(text,pattern)<<endl;
    return 0;
}