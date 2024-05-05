/*   minimum and maximum find karo along with and 
profit find karo*/

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &a){
   int top=a[0];
   int profit=INT_MIN;
   for(int i=1;i<a.size();i++){
        if(a[i]<top){
            top=a[i];
        }else{
            profit=max(profit,a[i]-top);
        }
   }
   return profit==INT_MIN?0:profit;
}