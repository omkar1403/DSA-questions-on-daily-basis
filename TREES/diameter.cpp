

class Solution {
    private:
    int solve(TreeNode* node,int &diameter){
        if(node==0)
            return 0;
        int lh=solve(node->left,diameter);
        int rh=solve(node->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);

         }

    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root,diameter);
         return diameter;
        
    }
};