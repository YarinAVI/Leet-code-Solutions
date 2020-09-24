/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)return head;
        queue<Node*> q;
        dfs(head,q);
        Node* flat = q.front();
        int i =0;
        Node * temp = nullptr;
        while(!q.empty()) {
            q.front()->prev = temp;
            temp = q.front();
            temp->child = nullptr;
            q.pop();
            if(!q.empty()) temp->next = q.front();
        }
        return flat;
    }
private:
    void dfs(Node* head,queue<Node*>&q) {
        while(head) { 
        while(head && head->child==NULL) q.push(head),head=head->next;
        if(head) q.push(head),dfs(head->child,q),head=head->next;
        }
    }
};