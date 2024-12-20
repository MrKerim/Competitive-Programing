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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        
        ListNode* temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            N++;
        }
        n = N - n; //remove n from the beginning (0 index)
        if(n==0){
            head = head->next;
            return head;
        }
        temp = head;
        ListNode* prev;
        int i = 0;
        while(i<n){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        return head;
    }
};