/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int ndigits=0;
    unsigned long long l1_num=0,l2_num=0;
    int sizeof_l1,sizeof_l2;
    struct ListNode* p1 = l1;
    struct ListNode* aux= NULL;
    struct ListNode* aux2= NULL;
    struct ListNode* p2 = l2;
    while(p1->next){
        ndigits++;
        p1=p1->next;
    }
    ndigits++;
    sizeof_l1=ndigits;
    int i =0;
    aux2=p1;
    p1=l1;
    // building numbers..
    while(ndigits){ 
        l1_num+=p1->val*pow(10,i);
        i++,ndigits--;
        p1=p1->next;
    }
    p2=l2;
        while(p2->next){
        ndigits++;
        p2=p2->next;
    }
    ndigits++;
    sizeof_l2=ndigits;
    if(sizeof_l1>=sizeof_l2) aux=aux2;
    else aux=p2;
    //printf("%x %x %x",aux,p1,p2);
    i=0;
    p1=l2;
    // building numbers..
    while(ndigits){ 
        l2_num+=p1->val*pow(10,i);
        i++,ndigits--;
        p1=p1->next;
    }
    //printf("%d ",l1_num);
    //printf("%d",l2_num);
    unsigned long long res = l1_num+l2_num;
    if(sizeof_l1>=sizeof_l2) p1=l1;
    else p1=l2;
    
    while(p1) {
        p1->val=res%10;
        res/=10;
        p1=p1->next;
    }
    //printf("%d",res);
    if(res>0) {
        if(sizeof_l1>=sizeof_l2) {
            aux->next = l2;
        l2->next = NULL;
        l2->val = res%10;
            return l1;
        } 
         else {
             aux->next = l1;
             l1->next=NULL;
             l1->val=res%10;
             return l2;
         }

    }
    if(sizeof_l1>=sizeof_l2) {
        return l1;
    }
    else return l2;
    
}