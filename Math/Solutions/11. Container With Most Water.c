#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int maxArea(int* height, int heightSize) {
    int max_area = INT_MIN;
    int area = 0;
    int i = 0, j = heightSize - 1;
    while (i < j) {
        area = min(height[i], height[j]) * (j - i);
        if (area > max_area) max_area = area;

        // since the area is limited by the lowest value by index then we reduce the pointers by the one having the largest value
        if (height[j] <= height[i]) j--;
        else i++;
    }
    return max_area;
}
int main() {
    int nums[7] = {1,3,2,5,25,24,5};
    printf("%d",maxArea(nums, sizeof(nums)/sizeof(nums[0])));
    
}