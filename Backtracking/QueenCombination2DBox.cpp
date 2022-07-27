#include<iostream>
using namespace std;
void QueenCombinationonBoard2D(bool ** board, int n, int row, int col, int qsfr, int tq, string ans){
    //when all queen will placed then print the ans;
    if(qsfr==tq){
        cout<<ans<<endl;
        return;
    }
    //when col will be exceed to board
    if(col==n){
        row++;
        col=0;
    }
    // when row will be exceed limit of board
    if(row==n){
        return;
    }
    //place Queen
    board[row][col]=true;
    QueenCombinationonBoard2D(board,n,row,col+1,qsfr+1,tq, ans+"{"+to_string(row)+","+to_string(col)+"}");
    board[row][col]=false; //undo
    //not place queen 
    QueenCombinationonBoard2D(board,n,row,col+1,qsfr,tq,ans);
}

using namespace std;
int main(){
    int n=2;
    string ans="";
    bool** board = new bool*[n];
    for(int i=0;i<n;i++){
        board[i]= new bool[n];
    }
    QueenCombinationonBoard2D(board,n,0,0,0,2,ans);
    for(int i=0;i<n;i++){
        delete[] board[i];
    }
    delete[] board;
    return 0;
}