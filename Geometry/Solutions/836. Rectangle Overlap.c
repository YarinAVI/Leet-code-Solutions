bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    // first we need to find rec2 postion relative to rec1 position
    if(rec1[3]<=rec2[1] || rec1[1]>=rec2[3]) return false;
    if(rec1[0]>=rec2[2] || rec1[2]<=rec2[0]) return false;
    
    return true;
}