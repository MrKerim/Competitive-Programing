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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        deque<int> dq;
        ListNode* temp = head;

        int n = 0;
        while(temp != nullptr ){
            dq.push_back(temp->val);
            temp = temp->next;
            n++;
        }

        k = k % n;
        while(k--){
            dq.push_front(dq.back());
            dq.pop_back();
        }

        temp = head;

        while(temp != nullptr){
            temp->val = dq.front();
            dq.pop_front();
            temp = temp->next;
        }

        return head;
    }
};