 int passThePillow(int n, int time) {
          int i=1;//this is starting from 1
          int find=0;
          int j=0;
          int ans=1;
          while(j<=time){ //here we start it from 0
            if(j==time){
               ans=i;
               return ans; //on j==time just return the answer 
            }
            if(i%n==0){
                find=1; //make this 1 to reverse the direction and it should be starting from 1
            }
            if(i==1){
                find=0;
            }
            if(find==0){
                ++i;
            }else{
                --i;
            }
           ++j;
          } 
          return ans;
    }

    //approach2

     int rounds = time/(n-1);
        int ans = 0;
        if(rounds%2 == 0){
            ans = (1+time%(n-1));
        }else{
            ans = (n-time%(n-1));
        }
        
        return ans;