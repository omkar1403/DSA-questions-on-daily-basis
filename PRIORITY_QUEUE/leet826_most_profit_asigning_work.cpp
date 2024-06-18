/*Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
Example 2:

Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0

soo hamne pahle isko pair banaya aur ek array me rakh diya aur phir usko sort kar diya on the basis of first element 
soo that ham usko difficulty ke hisab se asign kar sake.

aur worker ko bhi sort kar diya then hamne uske profit means array ke second element ko priority queue me dala 
and then we just check ki ye worker ki capbility se chhota hai na...agar hai to push their second element that is profit and return the top
wala element.

*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& worker) {
        int n=d.size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            ans.push_back({d[i],p[i]});
        }
       sort(ans.begin(),ans.end());
       sort(worker.begin(),worker.end());
       priority_queue<int>pq;
       int j=0;
       int maxprofit=0;
       for(int i=0;i<worker.size();i++){
           while(j<n && worker[i]>=ans[j].first){
            pq.push(ans[j].second);
            j++;
           }
         if(!pq.empty()){
           maxprofit+=pq.top();
           }
       }
        return maxprofit;
    }
};

