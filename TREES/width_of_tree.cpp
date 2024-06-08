/*please refer video first
isme ham pahle root and index save kar lenge and then we will see if there is some difference in 
the first and last index for every iteration then for each node we have to do the operation
1)first ham index create karenge to store level order traversal in 1 to n nodes ke format 
2)fir agar vo left and right me present hai to ham 2*index and 2*index+1 me store kar lenge
3)and we will update kyuki vo values overflow ho rahi thi soo it is necessary to convert it
into 1 to n ke format me start aur end index ko*/





int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,long long>>q1;
       
        q1.push({root,0});
        long long maxi=1;
        while(!q1.empty()){
           long long n=q1.size();
           long long start=q1.front().second;
           long long end=q1.back().second;
           maxi=max(maxi,end-start+1);

            for(int i=0;i<n;i++){
            pair<TreeNode*,int>p=q1.front();
            long long top=p.second-start;
            q1.pop();
            if(p.first->left!=NULL){
            q1.push({p.first->left,2*top+1});
            }
            if(p.first->right!=NULL){
            q1.push({p.first->right,2*top+2});
            }

            }
            
            
        }
        return maxi;
    }