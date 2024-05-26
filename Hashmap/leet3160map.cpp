/*isme hamne 2 maps use kiye hai one for mapping 0 to 1 and other for mapping total count of unique 
soo uss hisab se hamne kiya hai go through question just once*/



class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        vector<int>ans;
        map<int,int>mpp;
        map<int,int>mpp1;
        for(int i=0;i<q.size();i++){
            if(mpp.find(q[i][0])!=mpp.end()){
                mpp1[mpp[q[i][0]]]--;
                if(mpp1[mpp[q[i][0]]]==0){
                    mpp1.erase(mpp[q[i][0]]);
                }
            } 
           mpp[q[i][0]]=q[i][1];
           mpp1[q[i][1]]++;
           ans.push_back(mpp1.size());
        }


        return ans;
        
    }
};