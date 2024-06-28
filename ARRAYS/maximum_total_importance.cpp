

  long long maximumImportance(int n, vector<vector<int>>& roads) {
     long long  ans=0;
        vector<int>freq(n,0);   //here we are storing the frequency of each till n elements
        for(int i=0;i<roads.size();i++){   
            freq[roads[i][0]]++;
            freq[roads[i][1]]++;
        }
        sort(freq.begin(),freq.end()); //here we sort them 
        for(int i=0;i<n;i++){
            ans+=(long long) freq[i]*(i+1);//here we just direct give them number
        }
        return ans;
    }