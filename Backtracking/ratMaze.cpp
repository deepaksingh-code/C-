#include<iostream>
using namespace std;

void ratMaze(int** maze,int n, int row,int col,int ** solution){
    // when it reach to destination
    if(row==n-1&&col==n-1){
        solution[row][col]=1;
        cout<<"Result is: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // check when row is out of maze
    if(row==n){
        return;
    }
    //check when col is out of maze
    if(col==n){
        return;
    }
    // check blocker
    if(maze[row][col]==0){
        return;
    }
    solution[row][col]=1;
    ratMaze(maze,n,row,col+1,solution);
    ratMaze(maze,n,row+1,col,solution);
}
int main(){
    int n;
    cin>>n;
    
    int ** arr= new int*[n];
    for(int i=0;i<n;i++){
        arr[i]= new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ** sol= new int*[n];
    for(int i=0;i<n;i++){
        sol[i]= new int[n];
        for(int j=0;j<n;j++){
            sol[i][j]=0;
        }
    }   
    // rat maze function called
    ratMaze(arr,n,0,0,sol);
    
    for(int i=0;i<n;i++)
        delete[] sol[i];
    delete[] sol;
    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;    
    return 0;
}