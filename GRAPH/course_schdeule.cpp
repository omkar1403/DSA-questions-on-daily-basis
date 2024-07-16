/*inn this they have used topological order ki like agar jo pahle hai uske baad hi second wala aana chahiye nahi to return false
V.V.V.V.IMPORTANT first see adjacency list kaise create karte hai agar cycle hogi to vo topo create nahi kar payega so return false*/


 bool canFinish(int n, vector<vector<int>>&graph) {
        vector<int> adj[n];//IMP
        vector<int> indegree(n, 0);
       
     
       for(auto it:graph){
        adj[it[0]].push_back(it[1]);//v.v.IMPORTANT see how we can create adjacency list
       }
       
	   for(int i=0;i<n;i++){  
	       for(auto it:adj[i]){  //mark the all incoming edges and increase the frequency pf incoming edge
	          indegree[it]++; 
	       }
	   }
	   queue<int>q;
	   
	   for(int i=0;i<n;i++){
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
	   if(ans.size()==n){
        return true;    //here agar size is equal to n that means there exist topological order and there is no cycle else return false
       }
       return false;
        
    }