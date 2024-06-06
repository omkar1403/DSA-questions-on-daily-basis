/*isme hamne har ek traversal se check kiya ki ye equal hai ki nahi and then if one of them is NULL 
then we also check that ki vo same hai kya nahi and then we did preorder traversal*/




public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p==NULL || q==NULL){
         return (p==q);
      }
      return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
