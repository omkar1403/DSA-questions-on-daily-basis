/*isme hamne recursion ke through traversal kiya hai first hamne root find kiya aur uske left wale pehle aayenge then ham
uske right wale usme push karenge */




class Solution {

TreeNode* func1(vector<int>&preorder,int pstart,int pend,vector<int>&inorder,int istart,int iend,map<int,int>&mpp){
  if(pstart>pend || istart>iend){
    return NULL;
  }
  TreeNode* root=new TreeNode(preorder[pstart]);
  int inroot=mpp[root->val];

  int numsleft=inroot-istart;
  root->left=func1(preorder,pstart+1,pstart+numsleft,inorder,istart,inroot-1,mpp);
  root->right=func1(preorder,pstart+numsleft+1,pend,inorder,inroot+1,iend,mpp);

  return root;

}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=func1(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};