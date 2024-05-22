/*isme hamne un sabhi ko ordered manner me queue me save kiya first we push the root element 
and then we took the q ka size and then we run a loop jitna bhi vo q ka size hai and uske 
har ek node pe left ko aur right ko koi element hai kya and then uss hisab se ham queue
me uske left and right element ko push karenge and then usko 2d array me store karenge*/



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>ans1;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                ans1.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};