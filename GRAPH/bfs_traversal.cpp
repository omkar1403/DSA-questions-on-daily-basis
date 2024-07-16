/*isme ham queue maintain karke rakhenge and then we will push the data acoordingly
and it will have a size of V such that we will store each element in visited array 
if visited is not equal to 0 then we will insert it into queue and will mark it as 1
and then we will iterate till q is not empty and at the end we will return ans*/

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node); 
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
        return ans;
        
        
    }