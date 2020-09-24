


typedef struct CustomStack {
    int size;
    int maxSize;
    int *stack_elements;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack *obj = (CustomStack*)calloc(1,sizeof(CustomStack));
    obj->stack_elements = (int*)malloc(maxSize*sizeof(int));
    obj->maxSize = maxSize;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if(obj->size==obj->maxSize) return;
    obj->stack_elements[obj->size] = x;
    obj->size++;
   //printf("%d",x);
}

int customStackPop(CustomStack* obj) {
  if(obj->size) {
      obj->size--;
      return obj->stack_elements[obj->size];
  }
    return -1;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
  if(k>obj->size) k = obj->size;
    for(int i=0;i<k;i++) obj->stack_elements[i]+=val;
    
}

void customStackFree(CustomStack* obj) {
    free(obj->stack_elements);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/