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
    ListNode* partition(ListNode* head, int x) {
        queue<int> reg;
        queue<int> less;

        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->val < x) less.push(temp->val);
            else reg.push(temp->val);

            temp = temp->next;
        }

        temp = head;

        while(!less.empty()){
            temp->val = less.front();
            less.pop();
            temp = temp->next;
        }

        while(!reg.empty()){
            temp->val = reg.front();
            reg.pop();
            temp = temp->next;
        }

        return head;
    }
};