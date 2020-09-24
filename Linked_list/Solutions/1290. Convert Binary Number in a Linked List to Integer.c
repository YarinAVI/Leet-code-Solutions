/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int size=0;
    struct ListNode* temp =  head;
    while(temp) size++,temp=temp->next;
    int res = 0;
    temp = head;
    while(temp) {
        if(temp->val) res+=pow(2,size-1);
        temp=temp->next;
        size--;
    }
    return res;
}