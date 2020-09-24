#include <stdio.h>
#include <stdlib.h>
// leet code problem 
// https://leetcode.com/problems/distribute-candies/solution/
// approach in this solution is to first sort and then use logic - please reead the question first
int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}

int distributeCandies(int* candies, int candiesSize){
    int kinds=1,i;
    qsort(candies,candiesSize,sizeof(int),comparator);
    //for(i=0;i<candiesSize;i++) printf("%d ",candies[i]);
    
    for(i=0;i<candiesSize-1;i++) {
        if(candies[i+1]!=candies[i]) kinds++;
    }
    printf("%d ",kinds);
    if(kinds==candiesSize/2) return kinds;
    else {
        int max_can_take=candiesSize/2;
        if(max_can_take<kinds) return max_can_take;
        else if(kinds>=max_can_take) kinds=kinds-(max_can_take-kinds);
        return kinds;
    }
    return kinds;
}