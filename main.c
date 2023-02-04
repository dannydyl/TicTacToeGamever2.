
#include <stdio.h>
#include <stdlib.h>

typedef struct boardtype{
    char board[3][3];
    
} boardtype;

// boardtype bt;

void ClearBoard(boardtype *board){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                (*board).board[i][j] = ' ';
            }
    }
}


void PutMark(boardtype *board, char k, int i, int j){
    i--;
    j--;
    (*board).board[i][j] = k;
    	
}

int GetWinner(boardtype *board){
    int x, y;
    
    //check colums
    for(x=0;x<3;x++){
        
        if((*board).board[0][x] == (*board).board[1][x] && (*board).board[0][x] == (*board).board[2][x] && (*board).board[0][x] != ' '){
            printf("%c has won!1\n", (*board).board[0][x]);
            return 1;
        }
    }
    
    //check rows
    for(y=0;y<3;y++){
        if((*board).board[y][0] == (*board).board[y][1] && (*board).board[y][0] == (*board).board[y][2] && (*board).board[y][0] != ' '){
            printf("%c has won!2\n", (*board).board[y][0]);
            return 1;
        }
    }
    
    //check diagonals
    if((*board).board[0][0] == (*board).board[1][1] && (*board).board[0][0] == (*board).board [2][2] && (*board).board[1][1] != ' '){
        printf("%c has won!3\n", (*board).board[0][0]);
        return 1;
    }
    if((*board).board[0][2] == (*board).board[1][1] && (*board).board[0][2] == (*board).board[2][0] && (*board).board[1][1] != ' '){
        printf("%c has won!4\n", (*board).board[1][1]);
        return 1;
    }
    
    return 0;
}

void DisplayBoard(boardtype *board){
    printf("---------------\n");
    printf("| %c | %c | %c |", (*board).board[0][0], (*board).board[0][1], (*board).board[0][2]);
    printf("\n|---|---|---|\n");
    printf("| %c | %c | %c |", (*board).board[1][0], (*board).board[1][1], (*board).board[1][2]);
    printf("\n|---|---|---|\n");
    printf("| %c | %c | %c |\n", (*board).board[2][0], (*board).board[2][1], (*board).board[2][2]);
    printf("---------------\n");
}



int main() {
    boardtype board;
    //aboard = (boardtype *)malloc(sizeof(boardtype));
    //define instance of the ADT
    ClearBoard(&board);
    int row, col, moveNum=0;

    while(GetWinner(&board) != 1 && moveNum < 9){
        printf("Enter player 1 row: ");
        scanf("%d", &row);
        printf("Enter player 1 column: ");
        scanf("%d", &col);
        
        
        PutMark(&board,'X', row, col);
        DisplayBoard(&board);
        GetWinner(&board);
        moveNum++;
        
        if(GetWinner(&board) == 1 || moveNum == 9){
            break;
        }
        
        printf("Enter player 2 row: ");
        scanf("%d", &row);
        printf("Enter player 2 column: ");
        scanf("%d", &col);
        
        PutMark(&board, 'O', row, col);
        DisplayBoard(&board);
        GetWinner(&board);
        moveNum++;
        
        if(moveNum == 10){
            break;
        }
        printf("\n-----%d-----\n", moveNum);
    }
    
    if(GetWinner(&board) == 1){
        exit(0);
    }
    else if(moveNum == 9){
        printf("It is a draw\n");
    }
    
    return 0;
}
