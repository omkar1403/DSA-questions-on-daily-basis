/*agar samjh value ye kam hogi dono ki bhi to left ki taraf jayenge else 
agar jyada hogi to right ki taraf jayange else agar jis root pe hame ek ki kam 
aur ek ki jyada aise seperate karne wala node mil jaye means root to ham usko return kar denge
*/



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        int curr=root->val;
        if(curr>p->val && curr>q->val){
           return lowestCommonAncestor(root->left,p,q);
        }else if(curr<p->val && curr<q->val){
           return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};