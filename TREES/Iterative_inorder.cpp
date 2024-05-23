 /*isme hamne ek stack maintain kiya ki agar NULL nahi hoga to node ke left me jayenge else 
 satck me se pop karke answer me dalenge aur uske right me jayenge jab tak ki loop hai aur 
 agar stack empty ho gayio to break karenge */
 
 
 vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*>st;
        TreeNode* node=root;
       
        while(true){
         if(node!=NULL){
            st.push(node);
            node=node->left;
         }else{
            if(st.empty()){
                break;
            }
            node=st.top();
            ans.push_back(node->val);
            st.pop();
            node=node->right;
         }
        }
        return ans;
    }