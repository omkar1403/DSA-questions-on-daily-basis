/*isme first we have mapped the array into 2d and we have to generate the maximum profit keeping w(initial investment) as it is
if we have to generate maximum profit then we have to sort them first according to the capital and then we have to pick the
profit of that element whose capital value is less than or equal to our initial investment.and if the queue is empty that means 
our initial investment is less than minimum capital so break the loop
*/



class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while(k--){
            while(i<n && projects[i].first<=w){
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if(maximizeCapital.empty()){
                break;
            }
            w+=maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;

    }
};