/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* swapList(ListNode* root){
    if (root == nullptr) return nullptr;
    if (root->next == nullptr) return root;

    ListNode* next = swapList(root->next->next);
    ListNode* temp = root->next;
    temp->next = root;
    root->next = next;
    return temp;
    
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return swapList(head);
    }
};