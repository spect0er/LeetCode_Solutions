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
    void merge(stack<ListNode*> &s1,stack<ListNode*> &s2,int &carry){
        while(!s2.empty()){
            int value = s1.top()->val + s2.top()->val + carry;
            carry = value / 10;
            s1.top()->val = value % 10;
            s1.pop();
            s2.pop();
        }
        while(!s1.empty()){
            int value = s1.top()->val + carry;
            carry = value / 10;
            s1.top()->val = value % 10;
            s1.pop();
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1){
            s1.push(t1);
            t1 = t1->next;
        }
        while(t2){
            s2.push(t2);
            t2 = t2->next;
        }
        int carry = 0;
        if(s1.size() > s2.size()){
            merge(s1,s2,carry);
            if(carry != 0){
                ListNode* carrNode = new ListNode(carry);
                carrNode->next = l1;
                l1 = carrNode;
            }
            return l1;
        }else{
            merge(s2,s1,carry);
            if(carry != 0){
                ListNode* carrNode = new ListNode(carry);
                carrNode->next = l2;
                l2 = carrNode;
            }
            return l2;

        }
    }
};