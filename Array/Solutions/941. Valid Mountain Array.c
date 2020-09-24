#include <stdio.h>
#include <stdbool.h>
bool validMountainArray(int* A, int ASize){
    if(ASize<3) return false;
    if(ASize==3) {
        if(A[1]>A[0]) {
            if(A[1]>A[2]) return true;
            else return false;
        }
        return false;
    }
    int i=0,f=0;
    while(A[i+1]>A[i] && i<ASize-2) f++,i++;
    if(f==0) return false;
    f=0;
    while(A[i+1]<A[i] && i<ASize-2) f++,i++;
    if(A[i+1]>=A[i]) return false;
    if(f==0 && i+1!=ASize-1) return false;
    return true;
}

int main () {
    int input[11] = {0,1,2,3,4,8,9,10,11,12,11};
    int s=sizeof(input)/sizeof(input[0]);
    printf("%d",validMountainArray(input,s));

}
