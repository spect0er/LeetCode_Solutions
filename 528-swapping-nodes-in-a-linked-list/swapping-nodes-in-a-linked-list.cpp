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
    ListNode* swapNodes(ListNode* head, int k) {
        int totalNodes = 0;
        ListNode* temp = head;
        ListNode* s1;
        while(temp){
            totalNodes++;
            if(totalNodes == k) s1 = temp;
            temp = temp->next;
        }
        totalNodes = totalNodes - k + 1;
        temp = head;
        while(--totalNodes){
            temp = temp->next;
        }
        ListNode* s2 = temp;
        swap(s1->val, s2->val);
        return head;
    }
};