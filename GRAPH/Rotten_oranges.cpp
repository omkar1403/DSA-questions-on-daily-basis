


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;//isme ham row,column aur uske sath time store karenge
       int vis[n][m];   //this is for visited element

        int startcount=0;  //here is starting count to check the number of 1s to the 1s jo last me rotten hone wale hai
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});//as we push row and column
                    vis[i][j]=2;  //here mark the array as visited if oranges are visited
                }else{
                    vis[i][j]=0;  //else we will visited as 0
                }
                if(grid[i][j]==1){
                    startcount++; //here we increase the count if it is 1
                }
            }
        }

    int time_to_computed=0;   //this is the actual time to be computed
    int nrow[4]={-1,0,1,0};    //this are the rows when we move up,right,down,left
    int ncol[4]={0,1,0,-1};    //......are columns..........
    int count=0;    //this count will be compared with the startcount to check ki sab ke sab oranges vo rotten ho gaye hai kya
     while(!q.empty()){
     int row=q.front().first.first;  //here is the row
     int col=q.front().first.second;  //column
     int t=q.front().second;   //time 
     q.pop();

     time_to_computed=max(time_to_computed,t);  //here we take the maximum of both and then return it
     for(int i=0;i<4;i++){
        int r1=row+nrow[i];   //here we add the horizontal cell(row)  to check if there is fresh orange
        int c1=col+ncol[i];   //here we add vertical cell(column)   ..........
        if(r1>=0 && r1<n && c1>=0 && c1<m && grid[r1][c1]==1 && vis[r1][c1]==0){  //if visited equal to 0 and grid value =1 then overflow condition then we will push into queue
            q.push({{r1,c1},t+1});  //here we push into the queue
            vis[r1][c1]=2;    //here we mark the visited as 1
            count++;  //here we make the count of rotten oranges
        }
     }
     }

     if(startcount!=count){ //now here we compare that all oranges are rotten or not
        return -1;
     }
    
return time_to_computed;

    }
};