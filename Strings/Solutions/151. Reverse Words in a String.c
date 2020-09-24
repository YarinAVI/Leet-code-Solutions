#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "H:\uthash-master\src\uthash.h"
//written by yarin avisidris
struct node {
    char* word;
    int size_of_word;
    struct node* next;
};
void add_word(struct node** head, char* s, int str_size) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->word = (char*)malloc(str_size);
    new_node->size_of_word = str_size;
    memcpy(new_node->word, s, str_size);
    new_node->next = *head;
    *head = new_node;
}
void parse(struct node** head, char* origin) {
    struct node* rm = NULL;
    while (*head) {
        memcpy(origin, (*head)->word, (*head)->size_of_word);
        origin = &origin[(*head)->size_of_word];
        if ((*head)->next == NULL) *origin = 0;
        else {
            *origin = ' ';
            origin++;
        }
        rm = *head;
        *head = (*head)->next;
        free(rm);
    }
}
char* reverseWords(char* s) {
    char* origin = s;
    struct node* head = NULL;
    int i = 0, size = strlen(s);
    int x, str_size = 0;
    while (*s) {
        while (s[i] == ' ' && s[i]) i++;
        x = i;
        if (!s[i]) break;
        while (s[i] != ' ' && s[i]) str_size++, i++;
        s = &s[x];
        add_word(&head, s, str_size);
        s = &s[str_size];
        i = 0;
        str_size = 0;
    }
    s = origin;
    //memset(origin, 0, size - 1);
    parse(&head, origin);
    return origin;
}
int main() {
    //char s[16] = "the sky is blue";
    //char s[17] = "a good   example";
    //char s[17] = "  hello world!  ";
    char s[13] = "hello world!";
        printf("%s", reverseWords(s));
}