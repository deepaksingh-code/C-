#include<iostream>
using namespace std;

int* kadenesAlgo(int* arr, int n){
    cout<<"kadenes called"<<endl;
    int * r= new int[3];
    int max_so_far=-1000;
    int max_ending_here=0;
    int start=0;
    int end=0;  
    int s=0;
    for(int i=0;i<n;i++){
        max_ending_here= max_ending_here+arr[i];
        if(max_so_far<max_ending_here){
            max_so_far=max_ending_here;
            start=s;
            end=i;
        }
        if(max_ending_here<0){
            max_ending_here=0;
            s=s+1;
        }
    }
    r[0]=start;
    r[1]=end;
    r[2]=max_so_far;
    return r;
}

int maxSumReactangle(int** arr, int row, int column){
    cout<<"maxSumreact called"<<endl;
    int* a= new int[row];
    cout<<"array created"<<endl;
    int maxSum=-1000;
    int upperMax=0,lowerMax=0;
    int leftMAX=0,rightMax=0;
    for(int i=0;i<column;i++){
        for(int l=0;l<row;l++){
                a[l]=0;
            }
        //cout<<"array intialized"<<endl;
        for(int j=i;j<column;j++){
            //cout<<"inside i and j"<<endl;
            for(int k=0;k<row;k++){
                a[k]=a[k]+arr[k][j];
            }
            //cout<<endl<<"print a: "<<endl;
            // for(int l=0;l<row;l++){
            //     cout<<a[l]<<" ";
            // }
            //cout<<endl;
            //cout<<"calculated array";
            int * result=kadenesAlgo(a,row);
            cout<<"upper: "<<result[0]<<" lower: "<<result[1]<<" maxSum: "<<result[2]<<endl;
            if(result[2]>maxSum){
                maxSum=result[2];
                leftMAX=i;
                rightMax=j;
                upperMax=result[0];
                lowerMax=result[1];
            }
        }
    }
    cout<<"left: "<<leftMAX<<" right: "<<rightMax<<" upper: "<<upperMax<<" lower: "<<lowerMax<<" maxSum: "<<maxSum<<endl;
    return maxSum;
}
int main(){
    int row,col;
    cout<<"Enter row and column: ";
    cin>>row>>col;
    int **arr = new int*[row];
    cout<<"input array : "<<endl;
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"inputDone"<<endl;
    cout<<"Maximum sum: "<<maxSumReactangle(arr,row,col)<<endl;
    return 0;
}