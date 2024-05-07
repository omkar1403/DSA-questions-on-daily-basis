/*  DELETION OF NODE AND THEY GIVE JUST SINGLE PARAMETER  SO ISME HAME SIRF EK CHAGE KARNA HAI KI 
JO NODE KE VALUE RAHEGI USKI JAGAH HAME SIRF NODE KI NEXT VALUE CONSIDER KARNI HAI AND USKE NODE KO USKE NEXT 
NODE SE CONNECT KARNA HAI

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       node->val=node->next->val;
       node->next=node->next->next;
    }
};