#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


int lengthOfLongestSubstring(char* s) {
    int max_size = strlen(s);
    int max = 0;
    int k = 0, f = 0;
    int i = 0, j = 0;
    char* map = (char*)calloc(95, sizeof(int));
    while ((i + j - f) < max_size) {
        if (map[s[i + j - f] - 32] == 0) map[s[i + j -f] - 32]++, j++, k++;
        else {
            map[s[i] - 32]--, i++, k--;
            f++;
        }
        if (k == max_size) return max_size;
        else if (k > max) max = k;
    }
    return max;
}

int main() {
    char s[100] = "aab";
    printf("%d", lengthOfLongestSubstring(s));
}