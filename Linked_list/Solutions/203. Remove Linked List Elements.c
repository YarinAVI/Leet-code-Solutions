/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* back =NULL;
    struct ListNode* cur =NULL;
    struct ListNode* front = NULL;
    if(!head) return head;
    
    while(head->val==val) {
    back=head;
    head=head->next;
    free(back);
    if(!head) return head;
    }
    cur=head;
    front=head->next;
    back=NULL;
    while(front){
        if(cur->val!=val) {
            back=cur;
            cur=front;
            front=front->next;
        }
        else {
            back->next = front;
            free(cur);
            cur=front;
            front=front->next;
        }
    }
    if(cur->val==val) {
        back->next=NULL;
        free(cur);
    }
    return head;
}