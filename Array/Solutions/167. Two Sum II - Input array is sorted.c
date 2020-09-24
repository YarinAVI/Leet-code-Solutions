
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res = (int*)malloc(2*sizeof(int));
    int i=0,j=numbersSize-1;
    while(i<j) {
        if(numbers[i]+numbers[j] == target) {
            *returnSize=2,res[0]=i+1,res[1]=j+1;
            return res;
        }
        else if(numbers[i]+numbers[j]<target) i++;
        else j--;
    }
    *returnSize=1,res[0]=-1;
    return res;
}