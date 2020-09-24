struct node {
    char val;
    struct node* next;
};
bool pop_check(struct node** head, char x) {
    if (x == '}' && (*head)->val != '{') return true;
    else if (x == ')' && (*head)->val != '(') return true;
    else if (x == ']' && (*head)->val != '[') return true;

    else {
        struct node* t = *head;
        *head = (*head)->next;
        free(t);
    }
    return false;
}
void addnode(struct node** head, char x) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = x;
    new_node->next = *head;
    *head = new_node;
}
bool isValid(char* s) {
    int i = 0;

    struct node* head = NULL;
    while (s[i]) {
        if (s[i] != '{' && s[i] != '}' && s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']') i++;

        else {
            if (head == NULL) {
                if (s[i] == '{' || s[i] == '[' || s[i] == '(') addnode(&head, s[i]);
                else if (s[i] == ')' || s[i] == ']' || s[i] == '}') return false;
                i++;
            }
            else {
                if (s[i] == '{' || s[i] == '[' || s[i] == '(') addnode(&head, s[i]);
                else {
                    if (pop_check(&head, s[i])) return false;
                }
                i++;
            }
        }
    }
    if (head) return false;
    return true;
}