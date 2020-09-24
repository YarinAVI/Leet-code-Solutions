//https://leetcode.com/problems/check-if-it-is-a-straight-line/
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    if(coordinatesSize==2) return true;
int i=0,j=1,d;
    if(coordinates[1][1]-coordinates[0][1]==0) {
        for(i=2;i<=coordinatesSize-1;i++,j++)  if(coordinates[j][1]-coordinates[i][1]!=0) return false;

        return true;

    }

        if(coordinates[1][0]-coordinates[0][0]==0) {
        for(i=2;i<=coordinatesSize-1;i++,j++) if(coordinates[j][0]-coordinates[i][0]!=0) return false;

        return true;

    }
int y = coordinates[1][1] - coordinates[0][1];
int x = coordinates[1][0] - coordinates[0][0];
d=y/x;
for(i=0,j=1;i<=coordinatesSize-2;i++,j++) {
int y = coordinates[j][1] - coordinates[i][1];
int x = coordinates[j][0] - coordinates[i][0];
if(x==0) return false;
if(y==0) return false;

if((y/x)!=d) return false;
    else d=y/x;
}
return true;
}