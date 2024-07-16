vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       vector<int>dist(N);
       vector<int>adj[N];
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);  //here it is undirected graph so we push both the edges
           adj[it[1]].push_back(it[0]);
       }

       
       for(int i=0;i<N;i++){
           dist[i]=1e9;
       }
       
       dist[src]=0;
       queue<int>q;
       q.push(src);
       
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto it:adj[node]){
               if(dist[node]+1<dist[it]){  //here check the condition ki greater hai kya agar nahi hai to update
                   dist[it]=dist[node]+1;
                   q.push(it);
               }
           }
       }
       vector<int>ans(N,-1);
       for(int i=0;i<N;i++){
           if(dist[i]==1e9){
               dist[i]=-1;
           }
       }
       return dist;
       
       
    }