#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
char ** commonChars(char ** A, int ASize, int* returnSize){
    u_int **table = (u_int **)malloc(ASize * sizeof(u_int*));
    char ** result = NULL;
    int i,j;
    (*returnSize) = 0;
    for(i=0;i<ASize;i++) table[i] = (u_int*)calloc(26,sizeof(u_int));
    for(i=0;i<ASize;i++) {
        for(j=0;A[i][j];j++) {
            table[i][A[i][j]-'a']++;
        }
    }
    for(i=0;i<26;i++) {
        int min =INT_MAX;
        for(j=0;j<ASize;j++) {
            
            if(table[j][i] <min) min = table[j][i];
        }
        while(min) {
            result = (char**)realloc(result,++(*returnSize)*sizeof(char*));
            result[(*returnSize)-1] = (char*)calloc(2,sizeof(char));
            result[(*returnSize)-1][0] = i+'a';
            min--;
        }
    }
    // free hash_table;
    for(i=0;i<ASize;i++) {
        free(table[i]);
    }
    free(table);
    return result;
}
int main() {
    int returnSize = 0;
    int ASize = 3;
    char ** words = (char**)malloc(ASize*sizeof(char*));
    words[0] = (char*)calloc(6,sizeof(char));
    words[1] = (char*)calloc(6,sizeof(char));
    words[2] = (char*)calloc(7,sizeof(char));
    int i;
    strcpy(words[0],"bella");
    strcpy(words[1],"label");
    strcpy(words[2],"roller");
    char **res = commonChars(words,ASize,&returnSize);
    for(i=0;i<returnSize;i++) free(res[i]);
    for(i=0;i<ASize;i++) free(words[i]);
    free(res);
    free(words);
}