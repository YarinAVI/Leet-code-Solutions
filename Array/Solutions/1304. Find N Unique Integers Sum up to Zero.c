/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// create a series of numbers and get their sum, the last element will get abs(thatSum) and will zero the array sum.
int* sumZero(int n, int* returnSize){
    *returnSize=n;
    int i;
    double sum;
    int *res = (int*)malloc(n*sizeof(int));
    if(n==1) {
        res[0]=0;
        return res;
    }
    sum=(-1-(n-1));
    sum/=2;
    sum*=(n-1);
    sum = (int)sum;
    
    for(i=0;i<n-1;i++) {
        res[i]=-(i+1);
    }
    res[n-1] = abs(sum);
    return res;
}