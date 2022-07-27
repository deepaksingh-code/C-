#include<iostream>
using namespace std;

bool isPossible(bool** board, int n, int row, int col){
    //cout<<"is possible called"<<endl;
    for(int i=0;i<n;i++){
        if(board[row][i]==true){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][col]==true){
            return false;
        }
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]==true){
            return false;
        }
    }
    for(int i=row,j=col;i<n&&j<n;i++,j++){
        if(board[i][j]==true){
            return false;
        }
    }
    for(int i=row,j=col;i<n&&j>=0;i++,j--){
        if(board[i][j]==true){
            return false;
        }
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]==true){
            return false;
        }
    }
    return true;
}
void nQueen(bool** board,int n, int row, int col, int qsfr, int tq, string ans){
    //cout<<"n Queens called"<<endl;
    if(qsfr==tq){
        cout<<ans<<endl;
        return;
    }
    if(col==n){
        col=0;
        row++;
    }
    if(row==n){
        return;
    }
    if(isPossible(board,n,row,col)){
        board[row][col]=true;
        nQueen(board,n,row,col+1,qsfr+1,tq,ans+to_string(row)+","+ to_string(col)+" ");
        board[row][col]=false;
    }
    nQueen(board,n,row,col+1,qsfr,tq,ans);
}

void nQueen2(bool** board, int n, int row, int qsfr, int tq, string ans){
    if(qsfr==tq){
        cout<<ans<<endl;
    }
    if(row==n){
        return;
    }
    for(int col=0;col<n;col++){
        if(isPossible(board,n,row,col)){
            board[row][col]=true;
            nQueen2(board,n, row+1, qsfr+1,tq, ans+"{"+to_string(row)+","+to_string(col)+ "} ");
            board[row][col]=false;
        }
        
    }
}
int main(){
    int n=4;
    string ans="";
    bool** board = new bool*[n];
    for(int i=0;i<n;i++){
        board[i]= new bool[n];
        for(int j=0;j<n;j++){
            board[i][j]=false;
        }
    }
    nQueen2(board,n,0,0,n,ans);
    //nQueen(board,n,0,0,0,4,ans);
    return 0;
}