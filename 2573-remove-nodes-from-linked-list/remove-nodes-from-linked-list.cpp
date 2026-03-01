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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp = head;
        int count = 0;
        while(temp){

            while(!st.empty() && st.top()->val < temp->val){
                st.pop();
            }
            st.push(temp);
            temp = temp->next;
            count++;
        }
        if(count == st.size()) return head;
        ListNode* h = NULL;        
        while(!st.empty()){
            st.top()->next = h;
            h = st.top();
            st.pop();
        }
        return h;
    }
};