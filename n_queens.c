//works good
#include<stdio.h>
#include<stdbool.h>
#define N 4
int solutions_count;
void printSol(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%2d",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool is_safe(int board[N][N],int row,int col){
    //no need to check things for right side is we place row wise and hence right coloumns will be already empty
    //also we dont need to check for cols as we are placing row wise and hence no piece will be place in current col
    int i,j;
    //check this row on left side
    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    //check upper diagonal on left side
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    //check lower diagonal on left side
    for(i=row,j=col;j>=0 && i<N;i++,j--){
        if(board[i][j]){
            return false;
        }
    }

    return true;
}
bool solveNQUtil(int board[N][N],int col){
    //if all queens placed then return true
    if(col>=N){
        solutions_count++;
        printf("solution %d :\n",solutions_count);
        printSol(board);
        return false;
    }
    //try placing queens in all rows one by one
    for(int i=0;i<N;i++){
        //check if it safe
        if(is_safe(board,i,col)){
            //place queen
            board[i][col]=1;
            //recursively call to place next queen
            if(solveNQUtil(board,col+1)){
                return true;
            }
            //if placing queen dont lead to a solution,remove the queen
            board[i][col]=0;
        }
    }
    return false;
}
bool solveNQ(){
    int board[N][N]={0};
    solutions_count=0;
    solveNQUtil(board,0);
    if(solutions_count==0){
        printf("Solution does not exist:");
    }
    else{
        printf("Total solutions : %d\n",solutions_count);
    }
    return true;
}
int main(){
    solveNQ();
    return 0;
}