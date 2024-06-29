


void dfs(vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& res, vector<bool>& visit) {
        visit[curr] = true;
        for (int dest : graph[curr]) {
            if (!visit[dest]) {
                res[dest].push_back(parent);//here we can push the parent of the the suppose 0,1 hai to 1 me jayega uska har ek componenet uss array me
                dfs(graph, parent, dest, res, visit); //here we call for dfs 
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      vector<vector<int>> res(n);
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);  //adjacency list 
        }
        
        for (int i = 0; i < n; ++i) {
            vector<bool> visit(n, false);  //here we make this false
            dfs(graph, i, i, res, visit);  //here we will call for dfs for particular position which is base node you can see here we have sent the i and then only destination is changing
        }
        
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());  //here we have sort the elements
        }
        
        return res;
    }