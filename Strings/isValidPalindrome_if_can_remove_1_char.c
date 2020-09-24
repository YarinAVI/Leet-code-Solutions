#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//judge either the text given to the function can be turn into a palindrome if you can remove at most 1 character
// solving : intuition > for checking palindromes we check pointing Beginning and end of the string, now this problem is different because we can remove one character
// so we check if we remove the character at the end pointer or at the beginning pointer is a palindrome if not then this string cannot be a palindrome if we remove 1 character
//https://leetcode.com/problems/valid-palindrome-ii/
bool valid(char *s , int i , int j) {
    while(i<=j) {
        if(s[i]==s[j])i++,j--;
        else return false;
    }
    return true;

}

bool validPalindrome(char * s){
int i =0 , j=strlen(s)-1;
    while(i<=j) {
        if(s[i]==s[j]) i++,j--;
        else return valid(s,i,j-1) || valid(s,i+1,j); // either way we need to check both possibilities if one is good then we continue
    }
    return true;
}

int main () {
    char s[100] = "deeedeeee";
    printf("%d",validPalindrome(s));
}
// TEST CASES :
/*
INPUT STRING:       OUTPUT:
    "cbbcc"         TRUE
    "deeee"         TRUE
    "deeedeeee"     FALSE
    "abca"          TRUE
    "aba"           TRUE
    "abag"          TRUE
    "abc"           FALSE
    "eddze"         TRUE
    "bbbb"          TRUE
*/


