// time limit exceeded algorithm not good sliding window !
// https://leetcode.com/problems/maximum-average-subarray-i/
double findMaxAverage(int* nums, int numsSize, int k){
double avg=INT_MIN,aux=0;
    int i=0,j=0;
    if(numsSize==1) return nums[0];
    //printf("%d ",numsSize);
    while(i<=numsSize-k) {
        for(j=0;j<k;j++) {
            aux+=nums[i+j];
        }
        if(aux > avg) avg=aux;
        aux=0;
        i++;
    }
    return avg/k;
}
// test cases::
//https://leetcode.com/submissions/detail/353540022/testcase/
//https://leetcode.com/submissions/detail/353545256/testcase/