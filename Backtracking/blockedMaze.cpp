#include<iostream>
using namespace std;

void blockedMaze(int** maze,int** visitor, int m, int n, int row, int col, string ans)
{
    //cout<<"BlockMaze called"<<endl;
    if(row==m-1 && col==n-1){
        cout<<ans<<endl;
        return;
    }
    if(row==m||row<0){
        return;
    }
    if(col==n||col<0){
        return;
    }
    if(maze[row][col]==1){ //check block 
        return;
    }
    if(maze[row][col]==-1){ //check if already visited
        return;
    }
    maze[row][col]=-1; // make as visited
    blockedMaze(maze,visitor,m,n,row+1,col,ans+"D");
    blockedMaze(maze,visitor,m,n,row,col-1,ans+"L");
    blockedMaze(maze,visitor,m,n,row,col+1,ans+"R");    
    blockedMaze(maze,visitor,m,n,row-1,col,ans+"T");
    maze[row][col]=0; //undo OR remove as visited
}
int main(){
    int n=4;
    int** maze = new int*[n];
    for(int i=0;i<n;i++){
        maze[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
    }
    blockedMaze(maze,maze,4,4,0,0,"");

    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int j = 0; j < n; j++)
    {
        delete[] maze[j];
    }
    delete [] maze;

    return 0;
}