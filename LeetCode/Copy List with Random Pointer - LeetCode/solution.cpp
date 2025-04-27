/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*,Node*> mp;
        Node* res = new Node(head->val);
        mp[head] = res;

        Node* org = head->next;
        Node* cpy = res;

        while(org != nullptr){
            cpy->next = new Node(org->val);
            cpy = cpy->next;
            mp[org] = cpy;
            org = org->next;
        }

        org = head;
        cpy = res;

        while(org!=nullptr){
            cpy->random = mp[org->random];
            org = org->next;
            cpy = cpy->next;
        }

        return res;
    }
};