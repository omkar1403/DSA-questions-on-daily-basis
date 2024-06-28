/*this is bfs solution*/

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   int indegree[V]={0};
	   for(int i=0;i<V;i++){  
	       for(auto it:adj[i]){  //mark the all incoming edges and increase the frequency pf incoming edge
	          indegree[it]++; 
	       }
	   }
	   queue<int>q;
	   
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0){ //here if it is 0 then we will push it into the queue
	           q.push(i);
	       }
	   }
	   vector<int>ans;
	   while(!q.empty()){
	       int k=q.front();
	       ans.push_back(k);  //here we push into array
	        q.pop();
	        for(auto it:adj[k]){
	            indegree[it]--;  //here we decrease the array of that particular incoming edge
	            if(indegree[it]==0){  //if it becomes 0 then we will push into the queue and return the answer
	                q.push(it);  
	            }
	        }
	   }
	   return ans;
	}