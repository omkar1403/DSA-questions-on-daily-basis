 vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      vector<int>dist(V);
      for(int i=0;i<V;i++){
          dist[i]=1e9;
      }
      
      dist[src]=0;
      q.push({0,src});
      while(!q.empty()){
          int weight=q.top().first;
          int node=q.top().second;
          q.pop();
          for(auto it:adj[node]){
              int adjnode=it[0];
              int dist2=it[1];
              if(weight+dist2<dist[adjnode]){
                  dist[adjnode]=weight+dist2;
                  q.push({dist[adjnode],adjnode});
              }
          }
      }
      return dist;
      
    }
};