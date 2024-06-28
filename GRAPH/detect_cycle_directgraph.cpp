/*here we have to make the pathvis[node]=0 again soo that it will predict whether it is making cycle or not
time complexity is O(V+E)*/


bool dfs(int node, vector<int>adj[], int vis[], int pathvis[]) {
       vis[node]=1;
       pathvis[node]=1;
       for(auto i:adj[node]){
           if(!vis[i]){
             if(dfs(i,adj,vis,pathvis)==true){ //if it is true and not visited then return true
                 return true;
             }  
           }else if(pathvis[i]){  //if it is also true then this initial point of cycle soo it is true
               return true;
           }
       }
       pathvis[node]=0; //make it 0 when return from the cycle
       return false;
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true){
                    return true;
                }
            }
        }
        
       return false; 
    }