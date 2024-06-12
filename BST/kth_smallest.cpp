/*just remember inorder traversal will always be in sorted order soo
if u did inorder traversal then U have to just return the element which is arr[k-1]*/

class Solution {
   void func(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        func(root->left,ans);
        ans.push_back(root->val);
        func(root->right,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        func(root,ans);
        return ans[k-1];
    }
};



/*in this approach u just did level order traversal and push the elements to the array 
and then sort the given array and return arr[k-1]*/


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<int>final1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                final1.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }

            }
        }
        sort(final1.begin(),final1.end());
        return final1[k-1];
    }
};