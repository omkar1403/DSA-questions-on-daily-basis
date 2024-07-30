
 int minimumDeletions(string s) {
        int n=s.length();
        int countb=0;
        int ans=0;
        for(auto i:s){
            if(i=='b'){
              countb++;   //here we will increase the count if it is B
            }else{
                ans=min(ans+1,countb);    //else we will find the minimum between ans+1 and countb
            }
        }
        return ans;
    }



       int minimumDeletions(string s) {
        int n = s.size(), cnt = 0, ans = 1e9;//pahle ham isko store karke rakhenge har ek ka count
        vector<int> cnta(n), cntb(n);

        for(int i=0; i<n; i++) {
            cntb[i] = cnt;
            if(s[i] == 'b') cnt++;//idhar ham iske piche kitne b hai vo store karenge
        }
        cnt = 0;
        for(int i=n-1; i>=0; i--) {
            cnta[i] = cnt;
            if(s[i] == 'a') cnt++; //idhar ham iske aage kitne a hai vo store karenge 
        }

        for(int i=0; i<n; i++) ans = min(ans, cnta[i] + cntb[i]); //idhar ham unn dono ko add karke inka minimum nikal lenge
        return ans;
    }