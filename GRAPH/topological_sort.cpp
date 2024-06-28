

	void dfs(int node,int vis[],stack<int>&st,vector<int>adj[]){
	    vis[node]=1;
	    for(auto adj1:adj[node]){
	        if(!vis[adj1]){
	            dfs(adj1,vis,st,adj); //idhar ham dfs ko call karenge aur uske sab adjacent values store karenge jo bhi unvisited hai
	        }
	    }
	    st.push(node); //here ham last me original node push karnege sab adjacent push karne ke baad taaki usko pahle nikal sake aur vo pahle aaye sab adjacent node ke
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   int vis[V]={0};
	   stack<int>st;
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           dfs(i,vis,st,adj);  //if it is not visited then we will all dfs
	       }
	   }
	   vector<int>ans;
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
	}