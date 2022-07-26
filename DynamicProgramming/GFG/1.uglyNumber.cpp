#include<iostream>
using namespace std;

int uglyNum(int n){
    int count=1;
    int i=0;
    while(count<n){
        if(count%2==0||count%3==0||count%5==0){
            count=count+1;   
        }
        i=i+1;
    }
    return i;
}
int main(){
    int n=7;
    cout<<"Ugly number is : "<<uglyNum(n)<<endl;
    return 0;
}