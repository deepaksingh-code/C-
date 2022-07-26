#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=INT8_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];

        }
    }
    cout<<"Maximum number is: "<<max<<endl;
    delete[] arr;
    return 0;
}