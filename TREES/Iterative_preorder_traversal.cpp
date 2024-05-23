/*in this i took stack and put the root into it and then one array of ans
we put value into the answer and if there exist right then we put right first and then left
because stack is last in first out soo jo last me dalenge vo pahle niklega soo left ko last me dalenge because 
it follows root-left-right*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            ans.push_back(node->val);
            st.pop();
            if(node->right!=NULL){
                st.push(node->right);
            }
            if(node->left!=NULL){
                st.push(node->left);
            }
        }
        return ans;
    }
};