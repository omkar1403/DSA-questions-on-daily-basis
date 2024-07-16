/*we have to find the start and destination ka path from teh root and then jo bhi common nodes honge we have to remove them
and uske baad left ki size jitni bhi hogi usme tu 'U' lagade aur uske baad wale isme string ko merge kar de right ke reverse se
*/


class Solution {
    bool get1(TreeNode* root1,int val1,string& path){
        if(root1->val==val1){
            return true;
        }
        if(root1->left && get1(root1->left,val1,path)){
            path.push_back('L');
        }else if(root1->right && get1(root1->right,val1,path)){
            path.push_back('R');
        }
       return !path.empty();
    }
public:
    string getDirections(TreeNode* root, int s, int d) {
       string left;
       string right;
       get1(root,s,left);
       get1(root,d,right);
     
       while(!left.empty() && !right.empty() && left.back()==right.back()){
        left.pop_back();
        right.pop_back();
       }
      string ans=string(left.size(),'U');
       reverse(right.begin(),right.end());
       ans.append(right);
      return ans;
    }
};