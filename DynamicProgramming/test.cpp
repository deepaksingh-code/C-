#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int * prise= new int[n];
    for(int i=0;i<n;i++){
        cin>>prise[i];
    }
    int ** arr= new int*[n];
    for(int i=0;i<n;i++){
        arr[i]= new int[n];
    }
    int year;
    int end=0;
    for(int i=0;i<n;i++){
        year=n-i;
        for(int j=0;j+end<n;j++){
            
            //cout<<"{("<<j<<","<<j+end<<"),("<<year<<","<<prise[i]<<")},";
            if(j==j+end){
                arr[j][j+end]=prise[j]*year;
            }
            else{
                arr[j][j+end]= max(arr[j][j+end-1]+(prise[j]*year),arr[j+1][j+end]+(prise[j+end]*year));
            }

        }
        end++;
        //cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"maximum profit is: "<<arr[n-1][n-1];

    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}