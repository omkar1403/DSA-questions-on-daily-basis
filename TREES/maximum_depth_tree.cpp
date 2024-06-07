/*maine kuch nahi kiya sirf level order traversal nikala jisme maine 2d array me push karna start kar diya and 
last me uske jitne bhi rows hai vo return kar diye accordingly means output.size()*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
       queue<TreeNode*>q;
       if(root==NULL){
        return 0;
       }
       int count=0;
       q.push(root);
       while(!q.empty()){
       int k=q.size();
       count++;
      for(int i=0;i<k;i++){
        TreeNode* node=q.front();

           q.pop();
           if(node->left !=NULL){
        q.push(node->left);
       }
       if(node->right !=NULL){
        q.push(node->right);
       }
          
       }
       

       }
       return count;

    }
};


/*approach 2 recursive 
isme hame recursively jana hai aur end me 1+max(left,right) return karna hai*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
     if(root==NULL){
        return 0;
     }
     int lh=maxDepth(root->left);
     int rh=maxDepth(root->right);
     return 1+max(lh,rh);
    }
};