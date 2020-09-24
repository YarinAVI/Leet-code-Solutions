bool search (char **board, int boardSize, int boardColSize, int r, int c, char * word, int wi) {
    char temp;
    //bool res =false;
    if(word[wi]=='\0') return true;
    else if(r>boardSize-1 || r< 0 || c>boardColSize-1 || c<0 || board[r][c] !=word[wi] ) return false;
    temp = board[r][c];
    board[r][c] = '*';
          if(search(board,boardSize,boardColSize,r+1,c,word,wi+1) ||
           search(board,boardSize,boardColSize,r-1,c,word,wi+1) ||
           search(board,boardSize,boardColSize,r,c+1,word,wi+1) ||
           search(board,boardSize,boardColSize,r,c-1,word,wi+1)) return true;
    board[r][c] = temp;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int i,j;
    int cz=*boardColSize;
    for(i=0;i<boardSize;i++) {
        for(j=0;j<cz;j++) {
            if(search(board,boardSize,cz,i,j,word,0))
                 return true;
        }
    }
    return false;
}