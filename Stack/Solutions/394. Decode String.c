struct node_times {
    int times;
    struct node_times* next;
};
struct node_char {
    char c;
    struct node_char* next;
};
void push_num(struct node_times** head, int num) {
    struct node_times* new_node = (struct node_times*)malloc(sizeof(struct node_times));
    new_node->times = num;
    new_node->next = *head;
    *head = new_node;
}
void push_char(struct node_char** head, char c) {
    struct node_char* new_node = (struct node_char*)malloc(sizeof(struct node_char));
    new_node->c = c;
    new_node->next = *head;
    *head = new_node;
}
int pop_number(struct node_times** head) {
    struct node_times* tmp = *head;
    int ret_n = tmp->times;
    *head = (*head)->next;
    free(tmp);
    return ret_n;
}
char pop_char(struct node_char** head) {
    struct node_char* tmp = *head;
    char ret_c = tmp->c;
    (*head) = (*head)->next;
    free(tmp);
    return ret_c;
}
int get_word_size(struct node_char* head) {
    int size = 0;
    while (head) {
        if (head->c == '[') break;
        size++;
        head = head->next;
    }
    return size;
}
char* decodeString(char* s) {
    struct node_times* head_num_stack = NULL;
    struct node_char* head_char_stack = NULL;
    int i = 0;
    int w_size;
    int k;
    while (s[i]) {
        // if its a number push it to number's stack
        if (s[i] >= '0' && s[i] <= '9') {
            int num = atoi(&s[i]);
            while (s[i] >= '0' && s[i] <= '9') i++;// increment index to pass by the number
            // push the number to numbers stack
            push_num(&head_num_stack, num);
        }
        else if (s[i] > '9' && s[i] != ']') {
            // if its any letter but not ']' then just push it to char stack
            push_char(&head_char_stack, s[i]);
            i++;
        }
        else if (s[i] == '[') {
            // if its an opnening bracket push it to char stack
            push_char(&head_char_stack, '[');
            i++;
        }
        else if (s[i] == ']') {
            // here we need building word procedure to begin
            w_size = get_word_size(head_char_stack); // get word size
            int n_times = pop_number(&head_num_stack); // get how much we need to repeat the word
            char* word = (char*)malloc(w_size * sizeof(char));// allocate memory for word for temporary work
            // read word chars into temporary word, also empty it from chars stack
            for (k = 0; k < w_size; k++) {
                word[k] = pop_char(&head_char_stack);
            }
            // now we have the word we need to push it the multiplier amount of times:
            // we have to push it in reversed order because we pulled it from char stack ( which is reversed )
            // and dont forget we need 1 null byte for ending string Muhahaha!
            pop_char(&head_char_stack); // get rid of the opening bracket at char stack - '['
            // now we need to push the word n_times
            for (; n_times > 0; n_times--) {
                for (k = w_size - 1; k >= 0; k--) {
                    push_char(&head_char_stack, word[k]);
                }
            }
            free(word); // free the temp string
            i++;
        }
    }
    // now we have the complete decoded string at the char_stack, all we need to do is to pop it out char by char and then reverse the chars order!
    w_size = get_word_size(head_char_stack);// get overall string size - how many chars
    char* res = (char*)calloc(w_size + 1, sizeof(char)); // allocate memory for solution string
    //free(s); // free memory of instruction string - this is optional 
    for (k = w_size - 1; k >= 0; k--) res[k] = pop_char(&head_char_stack); // copy the string in reversed order since we are pulling it from the stack!
    return res;
}

int main() {
    char input1[50] = "3[b2[ca]]"; // working
    char input2[50] = "3[a]2[bc]"; // working
    char input3[50] = "4100000[leetcode]"; // working
    char input4[50] = "abc3[cd]xyz"; // working
    char input5[50] = "c2[2[ba3[f]]]"; // working
    char input6[50] = "a1[2[b]]"; // working
    char input7[50] = "3[2[ca]]"; // working
    char input8[50] = "12[ff5[g3[asd2[ggg[3[gege]]]]]]"; // this is a wrong test case but somehow LC returns an answer for this, this will cause mem failure for my solution
    char input9[50] = "12[5[g2[c2[e]]]]"; // working
    char input10[50] = "3[f2[2[e]]]"; // working
    char input11[50] = "2[leetcode]"; // working
    char input12[50] = "2[2[g[3[c2[e]]]"; // wrong test case but still LC returns an answer different from mine
    char input13[50] = "2[2[g[2[e]]]]";
    printf("%s", decodeString(input3));
}