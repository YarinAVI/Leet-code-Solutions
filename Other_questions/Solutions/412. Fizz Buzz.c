

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
(*returnSize) = n;
    char **res = (char**)malloc((*returnSize)*sizeof(char*));
    int i;
    for(i=0;i<(*returnSize);i++) {
        if((i+1) %3 == 0 && (i+1) %5==0) {
            res[i] = (char*)calloc(9,sizeof(char));
            sprintf(res[i],"FizzBuzz");
        }
        else if((i+1) %3 ==0) {
            res[i] = (char*)calloc(5,sizeof(char));
            sprintf(res[i],"Fizz");
        }
        else if((i+1) %5 ==0) {
            res[i] = (char*)calloc(5,sizeof(char));
            sprintf(res[i],"Buzz");
        }
        else {
            res[i] = (char*)calloc(floor(log10(i+1))+2,sizeof(char));
            sprintf(res[i],"%d",i+1);
        }
    }
    return res;
}