struct node {
    char c;
    struct node * next;
};
char pop(struct node **head,int *stack_size) {
    struct node *rm = *head;
    char ret = rm->c;
    *head=(*head)->next;
    (*stack_size)--;
    free(rm);
    return ret;
}
void push(struct node**head,char c,int* stack_size) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(*head) {
    if((*head)->c == c) {
        pop(head,stack_size);
        return;
    }
    }
    new_node->c = c;
    new_node->next = *head;
    *head=new_node;
    (*stack_size)++;
}
char * removeDuplicates(char * S){
    struct node *head = NULL;
    int stack_size =0;
    int i=0,j=1;
    int sS = strlen(S);
    while(j<=sS) {
        if(S[i]!=S[j]) push(&head,S[i],&stack_size),i++,j++;
        else i+=2,j+=2;
    }
    printf("%d",stack_size);
    S[stack_size] =0;
    for(i=stack_size-1;i>=0;i--) {
        S[i] = pop(&head,&stack_size);
    }
    return S;
}