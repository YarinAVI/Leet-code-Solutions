/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
int ls=0;
    struct ListNode* t=head;
    while(t)ls++,t=t->next;
        int k=0;
        t=head;
        while(k<ls/2) k++,t=t->next;
        return t;

}