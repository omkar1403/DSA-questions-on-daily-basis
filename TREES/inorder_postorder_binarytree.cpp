/*here we have to add the element in the last index of an array and we have to try it recursively*/



class Solution {
    TreeNode* func1(vector<int>& postorder,int pstart,int pend,vector<int>& inorder,int istart,int iend,map<int,int>&mpp){
        if(pstart>pend || istart>iend){
            return NULL;
        }
       
        TreeNode* root1=new TreeNode(postorder[pend]);
         int inroot=mpp[root1->val];
        int numsleft=inroot-istart;
        root1->left=func1(postorder,pstart,pstart+numsleft-1,inorder,istart,inroot-1,mpp);//here we are inserting from the left
        root1->right=func1(postorder,pstart+numsleft,pend-1,inorder,inroot+1,iend,mpp);//here we are inserting at the end 
        return root1;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       map<int,int>mpp;
       for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
       } 
       return func1(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
       
    }
};