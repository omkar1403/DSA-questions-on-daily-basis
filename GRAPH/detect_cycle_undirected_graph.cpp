

bool detect(int src,vector<int>adj[],int vis[]){
     vis[src]=1;
     queue<pair<int,int>>q;
     q.push({src,-1});  //here we have stored the last visited
     while(!q.empty()){
         int node=q.front().first;//here we have first element
         int parent=q.front().second;
         q.pop();
         for(auto adj1:adj[node]){
             if(!vis[adj1]){
                 vis[adj1]=1;
                 q.push({adj1,node});
             }else if(parent!=adj1){ //important condition to find that it is not equal to adj1 and then return true
                 return true;
             }
         }
     }
     return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(!vis[i]){
                    if(detect(i,adj,vis)){  //here if it is not visited then we move to the function and then return true 
                        return true;
                    }
                }
            }
        }
        return false;
    }