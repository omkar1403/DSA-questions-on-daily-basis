/*isme ham direct vo root find karenge jisme hamne next value uski NULL mile and
aur agar data se bada hoga to right me shift karenge else left me shift karenge
and then new node insert karenge*/







class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* node1=new TreeNode(val);
            return node1;
        }else{
            TreeNode* node1=root;
            while(true){
                if(node1==NULL){
                    node1=new TreeNode(val);
                    break;
                }
                if(node1->val<val){
                    if(node1->right==NULL){
                    node1->right=new TreeNode(val);
                    break;
                }
                    node1=node1->right;
                }else if(node1->val>val){
                    if(node1->left==NULL){
                    node1->left=new TreeNode(val);
                    break;
                }
                    node1=node1->left;
                }
            }
           return root;
        }
    }
};