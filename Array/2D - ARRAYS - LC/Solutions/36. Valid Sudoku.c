#include <stdio.h>
#include <stdbool.h>
char hash[9] = {0,0,0,0,0,0,0,0,0}; // 0 is 1, 1 is 2 and so on... 8 is 9 ( index ), this will represent the counted numbers in rows / colums characters
/*char board[9][9] = {
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'},
};*/
char board[9][9] = {
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
  {'.','.','.','.','.','.','.','.','.'},
};
void counter(int num)  {
    switch(num) {
                case 49:
                    hash[0]++;
        break;
                case 50:
                    hash[1]++;
        break;
                case 51:
                    hash[2]++;
        break;
                case 52:
                    hash[3]++;

        break;
                case 53:
                    hash[4]++;

        break;
                case 54:
                    hash[5]++;

        break;
                case 55:
                    hash[6]++;

        break;
                case 56:
                    hash[7]++;

        break;
                case 57:
                    hash[8]++;

        break;

    }
    return;

}
bool isValidSudoku(int boardSize){
int c,i,j=0;
int limitC=boardSize/3;
int limitR=boardSize/3;
// column checking starts here!
for(c=0;c<boardSize;c++) {
for(i=0;i<boardSize;i++) {
    if(board[c][i]>=49 && board[c][i]<=57) counter(board[c][i]);
}
for(i=0;i<boardSize;i++) if(hash[i]>1) return false;
//clearing hashtable!
for(i=0;i<boardSize;i++) hash[i]=0;
}

// rows checking starts here!
for(c=0;c<boardSize;c++) {
for(i=0;i<boardSize;i++) {
    if(board[i][c]>=49 && board[i][c]<=57) counter(board[i][c]);
}
for(i=0;i<boardSize;i++) if(hash[i]>1) return false;
//clearing hashtable!
for(i=0;i<boardSize;i++) hash[i]=0;
}

for(i=0;i<boardSize;i++) hash[i]=0; // clear hash.
//3x3 boxes starts here, limit at begging is 3 increase each iteration 3

while(limitC<10){
while(limitR<10) {
for(j=limitR-3;j<limitR;j++) {

for(i=limitC-3;i<limitC;i++) {
    if(board[j][i]>=49 && board[j][i]<=57) counter(board[j][i]);
}
}
for(i=0;i<boardSize;i++) if(hash[i]>1)  return false; // checking
for(i=0;i<boardSize;i++) hash[i]=0; // clearing
limitR+=3;
}
limitR=3;
limitC+=3;
}
return true;
}
int main () {

int boardSize=sizeof(board)/sizeof(board[0]);

printf("%d",isValidSudoku(boardSize)); //
}
