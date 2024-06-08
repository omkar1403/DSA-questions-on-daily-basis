/*here we find the path fron the node aur to ham p aur q ka path nikalenge node ki help se 
aur phir ans1 ko set me dalenge and we will see if there is common element while iterating from the 
right side to get the lowest common answer*/



class Solution {

bool func(TreeNode* node,vector<int>&ans,int val1){
     if(node==NULL){
        return false;
     }
     ans.push_back(node->val);
     if(node->val==val1){
        return true;
     }
     if(func(node->left,ans,val1) || func(node->right,ans,val1)){
        return true;
     }
     ans.pop_back();
     return false;
    
}


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node1=p;
        TreeNode* node2=q;
        vector<int>ans1;
        vector<int>ans2;
   
      
        if(func(root,ans1,node1->val)){
            func(root,ans1,node1->val);
        };
        if(func(root,ans2,node2->val)){
            func(root,ans2,node2->val);
        }


        set<int>s1(ans1.begin(),ans1.end());
        for(int i=ans2.size()-1;i>=0;i--){    //here we are iterating from the right
            if(s1.find(ans2[i])!=s1.end()){
                node2->val=ans2[i];
                return node2;
            }
        }
        return node2;

    }
};