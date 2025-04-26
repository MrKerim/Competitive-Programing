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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* resHead = res;
        while(list2 != nullptr){
            if(list1 == nullptr){
                res->next = list2;
                list2 = list2->next;
                res = res->next;
                continue;
            }

            if(list1->val < list2->val){
                res->next = list1;
                list1 = list1 -> next;
                res = res->next;
                continue;
            }

            res->next = list2;
            list2 = list2->next;
            res = res->next;
        }

        while(list1 != nullptr){
            res->next = list1;
            list1 = list1 -> next;
            res = res->next;
        }


        return resHead->next;
    }
};