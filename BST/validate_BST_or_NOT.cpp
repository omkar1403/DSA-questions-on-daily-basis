/*here we kept a track of upper and lower limit accordingly and 
if lower value is greater than or eqaul to node->val then return false
or if upper value is lesser than or equal to the the node->val then return false*/



class Solution {
    	bool validate(TreeNode* node, long lower, long upper){

			if( node == NULL ){
				// empty node or empty tree is valid always
				return true;
			}

			if( (lower >= node->val) || (node->val >= upper) ){
				// check if all tree nodes follow BST rule
                return false;
			}
			else{
                return validate(node->left, lower, node->val) && validate(node->right, node->val, upper);//here if there is left then we kept upper as node->val 
                //else if there is right then we kept lower as node->val

			}
		}

public:
    bool isValidBST(TreeNode* root) {
    return validate(root,std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }
};