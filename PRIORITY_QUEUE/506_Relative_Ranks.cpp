class Solution {
public:
    vector<string> findRelativeRanks(vector<int>&b) {
      priority_queue<int>q;
      for(int i=0;i<b.size();i++){
        q.push(b[i]);
      }

      map<int,string>ans;
      int k=1;

      while(!q.empty()){
       if(k==1){
        ans[q.top()]="Gold Medal";
       }else if(k==2){
        ans[q.top()]="Silver Medal";
       }else if(k==3){
        ans[q.top()]="Bronze Medal";
       }else{
        ans[q.top()]=to_string(k);
       }
       q.pop();
       k++;
    
      }
      vector<string>ans1;
      for(int i=0;i<b.size();i++){
        ans1.push_back(ans[b[i]]);
      }

    

      return ans1;


    }
};