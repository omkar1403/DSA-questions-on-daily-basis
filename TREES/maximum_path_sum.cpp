

/*very IMP question inorder to learn about tree*/
class Solution {
int sum1(TreeNode* node,int &maxi){
    if(node==0){
        return 0;
    }
    int lh=max(0,sum1(node->left,maxi));//does not consider negative unless its single element
    int rh=max(0,sum1(node->right,maxi));
    maxi=max(maxi,lh+rh+node->val);//add node->val also to calculate the current value itself also
    return node->val+max(lh,rh); //add maximum and node->val,maximum will be defined on the basis of individual sum of node
}

public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        sum1(root,maxi);
        return maxi;
    }
};