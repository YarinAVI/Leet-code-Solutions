

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize=ASize;
    int i=0 , j = ASize-1;
    int temp;
    while(i<j) {
        if(A[i]%2!=0 && A[j]%2==0) {
            temp = A[i];
            A[i]=A[j];
            A[j]=temp;
            i++,j--;
        }
        else if(A[i]%2!=0 && A[j]%2!=0) j--;
        else if(A[i]%2==0 && A[j]%2==0) i++;
        else i++,j--;
    }
    return A;
}