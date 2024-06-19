



 void func(vector<int> adj[],vector<int>&ans,int node,int vis[]){
      vis[node]=1;//here we have just given the node=1
      ans.push_back(node);//push it into the answer
      for(auto it:adj[node]){
          if(!vis[it]){//if it is not visited then 
          func(adj,ans,it,vis);//call iteratively for each element 
          }
      }
  }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int node=0;//starting node is 0
        int vis[V]={0}; //initialize the visited array with size of vertices
        vector<int>ans;
        func(adj,ans,node,vis);
        return ans;//returning the answer after calling
        
    }