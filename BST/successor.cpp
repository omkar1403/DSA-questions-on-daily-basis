/*isme hamne jo root->left hai usme final ki value store ki hai aur uss accordingly ham move karenge
to find the successor*/




class Solution{
 
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* final=NULL;
        while(root!=NULL){
            if(x->data>=root->data){
                root=root->right;
            }else{
                final=root;
                root=root->left;
            }
        }
        return final;
    }
};