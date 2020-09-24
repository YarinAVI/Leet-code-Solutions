#include <stdio.h>
int isBadVersion(int n) {
if(n==7) return 1;
else if (n<7) return 0;

}

int firstBadVersion(int n) {
    int left=0;
    int right =n;
    while(left<right) {
        int midpoint = left + (right-left) /2;
        if(isBadVersion(midpoint)) {
            right = midpoint;
        }
        else {
            left=midpoint+1;
        }
        }
    if(left==right && isBadVersion(left)) {
        return left;
    }
    return -1;
        }
int main () {

int n=15;
printf("%d",firstBadVersion(n));


}
