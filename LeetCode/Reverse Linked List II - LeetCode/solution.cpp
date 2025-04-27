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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> st;
        ListNode* temp = head;
        int index = 1;
        while(temp != nullptr){
            if(index>= left && index <= right) st.push(temp->val);
            index++;
            temp = temp->next;
        }

        temp = head;
        index = 1;
        while(temp != nullptr){
            if(index>= left && index <= right){
                temp->val = st.top();
                st.pop();
            }
            index++;
            temp = temp->next;
        }

        return head;
    }
};