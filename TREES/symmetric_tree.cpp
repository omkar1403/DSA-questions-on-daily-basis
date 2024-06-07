/*isme har ek baar we have to check that root ka left part ye root ke right part ke equal hai kya 
if not then we have to return the false*/


 bool func1(TreeNode* node1,TreeNode* node2){
        if(node1==NULL || node2==NULL){
            return node1==node2;
        }
        if(node1->val!=node2->val){
            return false;
        }
        return func1(node1->left,node2->right)&&func1(node1->right,node2->left);//here we have take node1->left and node2->right for iteration
    } //as well here we took node1->right and node2->left for comparison
  
public:
    bool isSymmetric(TreeNode* root) {
      if(root==NULL){
        return true;
      }
      return func1(root->left,root->right);
    }