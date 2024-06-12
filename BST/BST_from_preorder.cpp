/*In this we have to maintaiin the upper bound and if we move towards left then we have 
update the upper bound and agar ham right ke taraf honge to vo aisa hi rakhenge 
and at the end ham return the node*/



class Solution {
    TreeNode* func1(vector<int>& s,int &i,int bound){
        if(s.size()==i || s[i]>bound){
            return NULL;
        }
        TreeNode* node=new TreeNode(s[i]);
        i++;
        node->left=func1(s,i,node->val);
        node->right=func1(s,i,bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& s) {
        int i=0;
        return func1(s,i,INT_MAX);
    }
};