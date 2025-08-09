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



void search(Node* head, queue<Node*>& q){
    if(head == nullptr) return;

    q.push(head);

    if(head->child != nullptr) search(head->child,q);
    
    search(head->next,q);
}

class Solution {
public:
    Node* flatten(Node* head) {
        queue<Node *> q;
        search(head,q);

        Node* temp = head;
        if(head == nullptr) return nullptr;
        temp->child = nullptr;
        q.pop();
        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            current->prev = temp;
            temp->next = current;
            current->child = nullptr;

            temp = current;

        }


        return head;
    }
};