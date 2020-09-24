

char * tictactoe(int** moves, int movesSize, int* movesColSize){
    char ** table = (char**)malloc(3*sizeof(char*));
    int i,j;
    bool flag = 0;
    //char table[3][3] = {0};
    for(i=0;i<3;i++) table[i] = (char*)calloc(3,sizeof(char));
    for(i=0;i<movesSize;i++) {
        if(flag) {
            table[moves[i][0]][moves[i][1]] = 'O';
            flag=!flag;
        }
        else {
            table[moves[i][0]][moves[i][1]] = 'X';
            flag=!flag;
        }
    }
    int cx =0,co = 0,cp = 0;
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            if(table[i][j]=='X')cx++;
            else if(table[i][j]=='O')co++;
            else if(!table[i][j]) cp++;
        }
        if(cx==3) return "A";
        else if(co==3) return "B";
        cx=0,co=0;
    }
    cx=0,co=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++) {
            if(table[j][i]=='X')cx++;
            else if(table[j][i]=='O')co++;
            else if(!table[j][i]) cp++;
        }
        if(cx==3) return "A";
        else if(co==3) return "B";
        cx=0,co=0;
    }
    cx=0,co=0;
    for(i=0,j=0;i<3;i++,j++) {
                    if(table[i][j]=='X')cx++;
            else if(table[i][j]=='O')co++;
            else if(!table[i][j]) cp++;
    }
        if(cx==3) return "A";
        else if(co==3) return "B";
    cx=0,co=0;
    for(i=2,j=0;i>=0;i--,j++) {
            if(table[i][j]=='X')cx++;
            else if(table[i][j]=='O')co++;
            else if(!table[i][j]) cp++;
    }
            if(cx==3) return "A";
        else if(co==3) return "B";
    
    if(cp) return "Pending";
    return "Draw";
    
}