/*if you found the target value then return the root else return the NULL if it is NULL 
if root->val is less than target then move to the right else move to the left*/


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
         if (root->val == val) return root;
        else if(root->val > val) return searchBST(root->left,val);
        else return searchBST(root->right, val);
    }
};