/*basically jo hame first element milega for that particular line is our top view*/


  vector<int> topView(Node *root)
    {
         vector<int>ans;
      if(root==NULL){
      return ans;
      }
  map<int,int>mpp;   //In this we will asign the node->val to the each line, first element->line and second->element=node->val
  queue<pair<Node*,int>>q;//here I have used pair to store the first part of node and the line jo hame uniqly find karni hai for level order traversal
  q.push({root,0});//here we push root and the first line
  while(!q.empty()){
      auto it=q.front();
      q.pop();
      Node* node=it.first;//for node
      int k1=it.second;   //for line
      if(mpp.find(k1)==mpp.end()){   //here we find that if there is any line in the map
          mpp[k1]=node->data;        //if not then only we will add this
      }
      if(node->left!=NULL){          //then push node->left as well decrease by 1 as we go to the left 
         q.push({node->left,k1-1});  
      }
      if(node->right!=NULL){
         q.push({node->right,k1+1});     //then push node->right as well increase by 1 as we go to the right 
      }
  }

  for(auto i:mpp){
    ans.push_back(i.second);      //here we push the second element as it is data
  }
return ans;
    }
