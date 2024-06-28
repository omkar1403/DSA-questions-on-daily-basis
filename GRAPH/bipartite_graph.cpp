/*we have to ensure that no two adjacent will have the same color and color it with 0 and 1*/
  
  
  bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]){
                continue; //here if the color is given then we will continue
            }
            color[i]=0;  //initially color is 0
           q.push(i);
           while(!q.empty()){
                int cur=q.front(); 
                q.pop();
                for(int adj:graph[cur]){  //here we give the color to the adjacent nodes 
                    if(!color[adj]){
                        color[adj]=!color[cur];// give the color such that it is not a same color as adjacent color which is 1
                        q.push(adj);  //and push into the queue
                    }else if(color[adj]==color[cur]){ //if it is same color as parent 
                        return false;  //return false
                    }
                }
           }

        }
        return true;

    }