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

// Approach 1

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
          ListNode* curr=head;
        stack<int>st;
        int top=0;
        while(curr!=NULL){
            int data=curr->val;
            if(st.empty() || st.top()>=data){
                st.push(data);
            }else{
                while(!st.empty() && st.top()<data){
                    st.pop();
                }
                st.push(data);
            }
            curr=curr->next;
        }
        ListNode* temp=new ListNode(0);
    
        stack<int>st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        ListNode* curr1=temp;
     
        while(!st1.empty()){
            curr1->next=new ListNode(st1.top());
            curr1=curr1->next;
            st1.pop();
        }
        ListNode*temp1=temp;
        temp1=temp1->next;
        return temp1;
    }
};




//Approach 2 IMP(Using Linked list stack)

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != NULL) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};



