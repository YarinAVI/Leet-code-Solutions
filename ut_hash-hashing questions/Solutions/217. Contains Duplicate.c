#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "H:\uthash-master\src\uthash.h"
struct number_set {
    int value;
    UT_hash_handle hh;
};
bool containsDuplicate(int* nums, int numsSize)
{
    struct number_set* set = NULL;
    struct number_set* element;
    bool result = false;

    for (int i = 0; i < numsSize; ++i) {
        HASH_FIND_INT(set, &nums[i], element);
        if (element) {
            result = true;
            break;
        }

        element = (struct number_set*)malloc(sizeof(struct number_set));
        element->value = nums[i];
        HASH_ADD_INT(set, value, element);
    }

    /* Destroy the hashset */
    struct number_set* curr;
    struct number_set* tmp;
    HASH_ITER(hh, set, curr, tmp) {
        HASH_DEL(set, curr);
        free(curr);
    }

    return result;
}
int main() {
    int nums[10] = { 1,2,3,4,5,6,7,8,9,9 };
    printf("%d", containsDuplicate(nums, sizeof(nums) / sizeof(nums[0])));
}