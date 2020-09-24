/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) return;
    struct ListNode* cur = head->next;
    if(!cur) return head;
    struct ListNode* front=head->next->next;
    struct ListNode* back=head;
    while(front) {
        while(cur->val==back->val) {
            free(cur);
            cur=front;
            if(!front) break;
            front=front->next;
        }
        back->next=cur;
        back=cur;
        if(!cur) return head;
        cur=cur->next;
        if(!front) return head;
        front=front->next;
    }
    if(front==NULL && cur->val==back->val) {
        free(cur);
        back->next=NULL;
    }
    return head;
}