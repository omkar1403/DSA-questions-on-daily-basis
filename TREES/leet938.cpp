/*isme low aur high ke bich ki value karni thi so hamne ek limit lagayi and 
har ek node traverse kiya */



class Solution {
    void sum1(int& sum,TreeNode* node, int low, int high){
        if(node==NULL){
            return ;
        }
        if(node->val<=high && node->val>=low){
           sum=sum+node->val;
        }
        sum1(sum,node->left,low,high);
        sum1(sum,node->right,low,high);

    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum2=0;
        sum1(sum2,root,low,high);
        return sum2;
    }
};