/*isme hamne first topological order me sort kiya for that we maintain one stack soo that we can print 
fir main function me hamne ek adjacency list banayi jisme hamne uska number aur phir uske baad pair me uske baju wala
number aur uska weight aise store kiya and then hamne usko loop chalaya jab tak stack empty nahi ho jata
jisme hamne value node ki value store ki aur uske corresponding iske liye loop chalaya aur phir
check kiya ki agar dis[node]+wt < dist[v]  se chhote hai kya agar hai to update dis[v]=dis[node]+wt
else we will simply remain it as it is and then agar dist[v]=1e9 hoga to ham usko -1 se update kar denge*/


 void dfs(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st){
      vis[node]=1;
      for(auto it:adj[node]){
          int v=it.first;
          if(!vis[v]){
              dfs(v,adj,vis,st);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int points=it[2];
            adj[u].push_back({v,points});
        }
        
        int vis[N]={0};
        
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>dist(N);
         
        for(int i=0;i<N;i++){
            dist[i]=1e9;
        }
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[v]){
                    dist[v]=wt+dist[node];
                }
            }
        }
         for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
        return dist;
        
    }