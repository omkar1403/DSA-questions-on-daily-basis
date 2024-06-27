/*In this surrounded regions we first mark jo border ke elements hai aur jo O hai unko 1 mark kiya
and then usko queue me push kiya and then agar q empty nahi hai to phir hamne loop chalaya aur baaki sab jo bhi uske adjacent hai usko mark karke
hamne unko visited mark kar diya aur 
phir check kiya ki agar visited nahhi hai aur vo O hai to hamne usko X kar diya*/


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){  
            if(board[i][0]=='O' && !vis[i][0]){  //first column
                vis[i][0]=1;
                q.push({i,0});
            }
             if(board[i][m-1]=='O' && !vis[i][m-1]){ //last column
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){  //first row
                vis[0][i]=1;
                q.push({0,i});
            }
             if(board[n-1][i]=='O' && !vis[n-1][i]){  //last row
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
                int newrow=row+row1[i];
                int newcol=col+col1[i];

                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && board[newrow][newcol]=='O'){
                    vis[newrow][newcol]=1;  //visited as 1
                    q.push({newrow,newcol});
                }
            }      
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){  //jo bhi visited nahi hai aur O hai
                    board[i][j]='X'; //unko X kar diya
                }
            }
        }



    }
};