

void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis)
    {
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});   
    int row=grid.size();
    int col=grid[0].size();
    int delrow[4]={-1,0,1,0};//for up down left right rows
    int delcol[4]={0,1,0,-1};//........... for columns
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
        int newrow=r+delrow[k];  //for visiting up down left right in row
        int newcol=c+delcol[k];  //....................columns

        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]=='1' && !vis[newrow][newcol]) //if not visited and equal to '1' then mark it as visited
        {
            vis[newrow][newcol]=1;
            q.push({newrow,newcol});
        }
        }
        
    }
    }
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int count=0;
       for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(!vis[x][y] && grid[x][y]=='1'){ //here not visited and it is 1 then 
                bfs(grid,x,y,vis);
                count++; //increase count
            }
        }
       }
       return count;
    }