/*isme hame sirf last me uss line ke liye konsa element bachta hai vo dekhna hai sirf and 
to samjh agar vo element map me hoga bhi to bhi we have to replace it with the current node ka element
soo that only last element will be there till end and then we can print this element*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
    vector<int>ans1;
    if(root==NULL){
        return ans1;
    }
  queue<pair<Node*,int>>q1;
  map<int,int>mpp;
  q1.push({root,0});
  while(!q1.empty()){
      auto it=q1.front();
      Node* node=it.first;
      int ans=it.second;
      q1.pop();
      if(mpp.find(ans)==mpp.end()){
          mpp[ans]=node->data;
      }else{
          mpp[ans]=node->data;
      }
      if(node->left!=NULL){
          q1.push({node->left,ans-1});
      }
    if(node->right!=NULL){
          q1.push({node->right,ans+1});
      }

  }
  for(auto i:mpp){
    ans1.push_back(i.second);
  }
  return ans1;
    }
};