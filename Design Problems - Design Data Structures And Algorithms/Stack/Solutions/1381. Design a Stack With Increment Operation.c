typedef struct node {
    int data;
    struct node *next;
} CustomStack;

int stack_size;
int max_stack;
// initializing CustomStack pointer, we allocate a node for it and we only use it's ->next pointer, since we can pass that node
// and modify that ->next pointer origin.
CustomStack* customStackCreate(int maxSize) {
    CustomStack *top = (CustomStack*)malloc(sizeof(CustomStack));
    stack_size=0;
    max_stack = maxSize;
    top->next = NULL;
    return top;
}

void customStackPush(CustomStack* obj, int x) {
  if(stack_size<max_stack) {
   CustomStack * new_node = (CustomStack*)malloc(sizeof(CustomStack));
      new_node->data = x;
      new_node->next = obj->next;
      obj->next = new_node;
      //printf(" %d ",obj->next->data);
      stack_size++;
  }
}
int customStackPop(CustomStack* obj) {
  if(stack_size) {
      CustomStack * tmp = obj->next;
      int ret_num = obj->next->data;
      obj->next=obj->next->next;
      free(tmp);
      stack_size--;
      //printf(" %d ",ret_num);
      return ret_num;
  }
    else return -1;
}
void customStackIncrement(CustomStack* obj, int k, int val) {
    if(!stack_size) return;
    CustomStack *tmp = obj->next;
  if(k>=stack_size) {
      while(tmp)  {
          tmp->data +=val;
          tmp = tmp->next;
      }
  }
  else {
      int i = stack_size-k;
      while(i) {
          tmp=tmp->next;
          i--;
      }
      while(tmp) {
          tmp->data +=val;
          tmp = tmp->next;
      }
      
  }
}

void customStackFree(CustomStack* obj) {
    // freeing memory here
    while(obj->next) {
        CustomStack *tmp = obj->next;
        obj->next = obj->next->next;
        free(tmp);
    }
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/