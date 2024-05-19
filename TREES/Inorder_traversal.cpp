/*inorder me hamne first left then root and right lena hota hai soo we did the same 
but remember isme hamne initialize kaise kiya then how we print that all the things*/


class Solution {
 void preorder(vector<int>&ans,TreeNode* node){ //here we initialize the TreeNode* node
    if(node==nullptr){
        return;
    }
    preorder(ans,node->left);          //left me move karenge

    ans.push_back(node->val);          //here we put the element in array
    preorder(ans,node->right);          //here we move to right
 }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(ans,root);    //calling the function
        return ans;             ///return ans
    }
};