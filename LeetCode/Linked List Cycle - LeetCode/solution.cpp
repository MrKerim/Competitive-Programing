bool search(ListNode *head,ListNode* check){
    if(head->next == nullptr) return false;
    if(head->next->val == INT_MIN) return true;

    ListNode *nextNode = head->next;
    head->next = check;
    return search(nextNode,check);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* check = new ListNode();
        check->val = INT_MIN;


        return search(head,check);
    }
};