#include<bits/stdc++.h>
vector<int> primeNumbersTillN(int n) 
{ 
	vector<int>ans;
 	bool prime[n+1];
	 memset(prime,true,sizeof(prime));
	 for(int i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	 }

	 for(int i=2;i<=n;i++){
	 if(prime[i]){
		 ans.push_back(i);
	 }
	 }
	 return ans;
}

/*isme hamne different method use ki hai for finding prime numbers please go through it*/