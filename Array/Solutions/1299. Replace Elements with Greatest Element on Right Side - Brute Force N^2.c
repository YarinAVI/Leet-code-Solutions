/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    *returnSize=arrSize;
    int i=0,max=INT_MIN,j;
    for(i=0;i<arrSize-1;i++) {
        for(j=i+1;j<arrSize;j++) {
            if(arr[j]>max) max=arr[j];
        }
        arr[i]=max;
        max=INT_MIN;
    }
    arr[arrSize-1] = -1;
    return arr;
}