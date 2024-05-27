/*isme sirf hame check karna hai ki left aur right me height difference is greater
than 1 hai ki nahi agar if its greater than 1 then return false at any point
that suggests it is not balanced */

class Solution {
    bool ans;
 int maxDepth(TreeNode* root) {
     if(root==NULL){
        return 0;
     }
     if(ans==false){
        return 0;
     }
     int lh=maxDepth(root->left);
     int rh=maxDepth(root->right);
     if(abs(lh-rh)>1){
        ans=false;
     }
     return 1+max(lh,rh);
    }

public:
    bool isBalanced(TreeNode* root) {
       ans=true;
       int k=maxDepth(root);
       return ans;
    }
};