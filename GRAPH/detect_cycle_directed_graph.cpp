

 bool func(vector<int>adj[],int node,int parent,int vis[]){  
     vis[node]=1;
     for(auto i:adj[node]){
         if(!vis[i]){
         if(func(adj,i,node,vis)){ //here if any of them return true then we will return true 
             return true;
         }
         }else if(i!=parent){  //if the node is not parent then we will retirn true
             return true;
         }
     }
     return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
         int vis[V]={0};
       
        for(int i=0;i<V;i++){
            if(!vis[i]){  //if the node is not visited then we will run the recursion
            if(func(adj,i,-1,vis)){
                return true;
            }
            }
        }
        return false;
    }