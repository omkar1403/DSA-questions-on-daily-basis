/*isme hamne first jo bhi 0 hai unko visited me 1 mark kar diya and then hamne traverse kiya aur jitnne bhi side ke hai 
unko steps se count kiya aur unko steps asign ki hamne along with the row and column*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});   //jitne bhi 0 hai unke liye steps 0 hi rahange because vo khud 0 hai to unko 0 steps hi lagenge
                }else{
                    vis[i][j]=0;
                }
            }
        }

     int row1[]={-1,0,1,0};
     int col1[]={0,1,0,-1};

     while(!q.empty()){
        int row=q.front().first.first; //here we have stored row
        int col=q.front().first.second;//...     columns
        int steps=q.front().second;  //steps
        q.pop();
        dist[row][col]=steps;      //here we have stored the steps in particular elements

        for(int i=0;i<4;i++){
            int newrow=row+row1[i];
            int newcol=col+col1[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && vis[newrow][newcol]==0){ //if it is not visited then we put this as 0
                vis[newrow][newcol]=1;    //here we will store it as visited 
                q.push({{newrow,newcol},steps+1});    //and here the steps are increased by 1
            }
        }

     }
     return dist;  //here we calculate the distance

    }
};