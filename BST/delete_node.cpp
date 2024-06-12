/*in this we took helper function jisme ham rightchild ko ham ekdum node->left ka ekdum last wala jo right hai usse connect karenge and 
us node ka left return karenge and findlat se vo ham find karenge and 
main function me ham vo dekhnge ki data==key hai kya aur uss according ham usko split karenge*/





class Solution {
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findlast(root->left);
        lastright->right=rightchild;
        return root->left;
    }

    TreeNode* findlast(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return findlast(root->right);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};