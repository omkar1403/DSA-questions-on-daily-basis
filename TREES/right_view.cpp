



//APPROACH 1
void func(TreeNode* node,int level,vector<int>&ans){
    if(node==NULL){
        return ;
    }

    if(level==ans.size()){             //if level agar array ke size ke equal hoga then we will put it into the araay else not
        ans.push_back(node->val);
    }

    func(node->right,level+1,ans);   //we will traverse first to right because jo bhi elements hai agar right se dekhenge to right ke first element we have to take
    func(node->left,level+1,ans);   //after that we will take the element of the left and increase level from 1
}

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        } 
        func(root,0,ans);
     return ans;
    }


//APPROACH 2
//isme ham level order traversal karenge and then jo bhi last element store hoga array me vo push karenge


 vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q1;
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        q1.push(root);
        while(!q1.empty()){
           int n=q1.size();
           vector<int>temp;  //for storing the element
           for(int i=0;i<n;i++){
              TreeNode* node=q1.front();
              q1.pop();
              temp.push_back(node->val); //here we are storing the element in temp array
              if(node->left!=NULL){
                q1.push(node->left);
              }
              if(node->right!=NULL){
                q1.push(node->right);
              }
           }
           ans.push_back(temp[temp.size()-1]); //here we are storing the last element to get the right side view 

        }
     return ans;
    }