#include <iostream>
#include <vector>
#define n 4
using namespace std;

void printSolution(int board[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
           if(board[i][j])
            cout << "Q ";
           else cout<<". ";
        printf("\n");
    }
}

bool IsSafe(int board[n][n],int row, int col)
{
    int i,j;
    // checking the upper columns of given index//
    for(i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }
    //checks top left diagonal//
    for(i=row , j=col ; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    //checks top right diagonal//
    for(i=row , j=col ; i>=0 && j>n ; i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
class Solution{
public:
    bool NQueen(int board[n][n], int row){
        if(row>=n){
            return true;
        }
        for(int i =0 ; i<n ; i++){
            if(IsSafe(board,row,i)){
                // sets the queen if she is safe//
                board[row][i] = 1;
                //checks if the next queen can be placed correctly w.r.t prev queen//
                if(NQueen(board,row+1)){
                    return true;
                }
                //incase above condition fails, resets the prev pos//
                board[row][i] = 0;
            }
        }
        return false;
    }
};

int main(){
    int board[n][n] = { { 0, 0, 0, 0 },{ 0, 0, 0, 0 },{ 0, 0, 0, 0 },{ 0, 0, 0, 0 } };
    Solution o1;
    if(o1.NQueen(board,0)){
        printSolution(board);
    }
    else{
        cout << "no" << "\n";
    }
    return 0;
}