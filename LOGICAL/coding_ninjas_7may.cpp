#include <bits/stdc++.h> 
vector<int> theOrder(int n)
{
  vector<int>ans;
  map<int,int>mpp;
 
int predict=1;
int j=0;
long i=2;


while(true){
	if(j==n){
		break;
	}
	long long k1=(i%n);
	if(k1==0){
		k1=n;
	}
	if(mpp.find(k1)!=mpp.end()){
		i++;
	}else{
		if(predict==1){
			ans.push_back(k1);
			predict=0;
			j++;
			mpp[k1]++;
		}else{
			predict=1;
		}
		i++;
	}
}

  return ans;
}