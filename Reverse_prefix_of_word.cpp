 string reversePrefix(string word, char ch) {
        int ans=-1;
        for(int i=0;i<word.length();i++){
          if(word[i]==ch){
             ans=i;
             break;
          }  
        }
        if(ans==-1){
            return word;
        }
        string ans1="";
        for(int i=ans;i>=0;i--){
           ans1.push_back(word[i]);
        }
        for(int i=ans+1;i<word.length();i++){
            ans1.push_back(word[i]);
        }
return ans1;
    }

  