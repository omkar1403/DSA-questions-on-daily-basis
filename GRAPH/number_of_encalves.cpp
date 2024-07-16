class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                vis[i][0]=1;
                q.push({i,0});
            }
              if(grid[i][m-1]==1 && vis[i][m-1]==0){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && vis[0][i]==0){
                vis[0][i]=1;
                q.push({0,i});
            }
              if(grid[n-1][i]==1 && vis[n-1][i]==0){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }

        int row1[]={-1,0,1,0};
        int col1[]={0,1,0,-1};

        while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=row+row1[i];
            int ncol=col+col1[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){ //if it is 1 and not visited then mark it as visited and put in the queue
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){  //at the end jitne bhi bachenge jo unvisited honge aur 1 honge vo increament kar dena
                    count++;
                }
            }
        }
        return count;


    }
};