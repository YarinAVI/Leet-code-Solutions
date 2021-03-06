//https://leetcode.com/problems/valid-tic-tac-toe-state/submissions/
// check if the given game state is possible or not

bool validTicTacToe(char ** board, int boardSize){
int oC=0, xC=0;
    int wO=0,wX=0;
    // first we count amount of X and O
    int i,j;
    //printf("%d ",boardSize);
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            if(board[i][j]=='X') xC++;
            else if(board[i][j]=='O') oC++;
        }
    }
    if(oC>xC || xC>=oC+2) return false;
    // checking for winners
    // rows check
        for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            if(board[i][j]=='X') wX++;
            else if(board[i][j]=='O') wO++;
        }
            // if X wins xC must be oC+1;
            // if O wins xC must be equal to oC
            if(wX==3 && xC!=oC+1) return false;
            if(wO==3 && xC!=oC) return false;
            wX=0,wO=0;
    }
    // column check
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            if(board[j][i]=='X') wX++;
            else if(board[j][i]=='O') wO++;
        }
            // if X wins xC must be oC+1;
            // if O wins xC must be equal to oC
            if(wX==3 && xC!=oC+1) return false;
            if(wO==3 && xC!=oC) return false;
            wX=0,wO=0;
    }
    wX=0,wO=0;
    // diagonal check left to right
    for(i=0,j=0;i<3;i++,j++) {
        if(board[i][j]=='X') wX++;
        else if(board[i][j]=='O') wO++;
    }
    if(wX==3 && xC!=oC+1) return false;
    if(wO==3 && xC!=oC) return false;
        // diagonal check right to left
    wX=0,wO=0;
    for(i=2,j=0;i>=0;i--,j++) {
        if(board[i][j]=='X') wX++;
        else if(board[i][j]=='O') wO++;
    }
    if(wX==3 && xC!=oC+1) return false;
    if(wO==3 && xC!=oC) return false;
    printf("%d %d %d %d",xC,oC,wX,wO);
    return true;
}