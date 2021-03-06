int series_sum(int start, int count_times) {
    //double ser = (double)((double)start + 1 + ((double)start + count_times - 1)) / 2;
    //ser *= ((double)count_times - 1);
    int ret_val = start + ((double)(start + 1 + (start + count_times -1 )) / 2 * (count_times - 1));
    // 3 + 4 + 4 /2 *2
    //int ret_val = start + (int)ser;
    // 2 2 2 2 creates series of 2 3 4 5 where we do the calculation like this 2 + 3 + 4 + 5 instead of calculating using for loop we could use a math trick here
    // series from 3 to 5 can be calculated (3+5)/2 * count_times -1 ,where count_times is 4 so we calculate series of 3-5 and add 2 to it, we get 2+3+4+5.
    return ret_val;
}

int minIncrementForUnique(int* A, int ASize){
    // number of moves equals to original array sum subtracted by array sum of new constructed unique array.
    int *hash = (int*)calloc(40000,sizeof(int));
    int i=0,origin_sum=0,con_sum=0,max=INT_MIN;
    for(i=0;i<ASize;i++) {
        hash[A[i]]++;
        origin_sum+=A[i];
    }
    
    for(i=0;i<40000;i++) {
        if(hash[i]==1) {
            if(i>max) {
                con_sum+=i;
               max=i;
            }
            else {
                con_sum+=max+1;
                max+=1;
            }
        }
        else if(hash[i]>1) {
            if(i>max) {
                con_sum+=series_sum(i,hash[i]);
                max = i-1 + hash[i];
            }
            else {
                con_sum+=series_sum(max+1,hash[i]);
                max=max+hash[i];
            }
        }
        
    }
    //printf("%d %d",origin_sum,con_sum);
    return con_sum-origin_sum;
}