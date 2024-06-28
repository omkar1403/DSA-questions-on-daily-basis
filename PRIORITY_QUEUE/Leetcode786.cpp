/*Important isme ye hi hai ki how we can use priority_queue along with the pairs aur how we can convert
this into the double directly also how we can return the elements */

// APPROACH 1

 vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       int n = arr.size();
        //IMP:-here see how i created pair along with the priority queue we use 2 pairs one parent and one child 
        //this is how u can store them
        priority_queue<pair<double,pair<int,int>>> pq;   
        int a=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x = (arr[i]*1.0)/(arr[j]*1.0);//here how we can convert the 
                pq.push({x,{arr[i],arr[j]}});  //here how we can add the elements
                a++;
            }
        }
        int l=a-k;
        int i=0;
        while(i<l){
            pq.pop();//removing the total elements-k soo that we can get the exact top element
            i++;
        }

        return {pq.top().second.first,pq.top().second.second}; ///this is how we can convert return the element
    }




//APPROACH 2

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       int n = arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x = (arr[i]*1.0)/(arr[j]*1.0);
                //if size=k then agar current element chhota hai means he can be the top in queue soo add this else ignore 
                // else push karo directly agar size kam ho to that's it
                if(pq.size() == k){
                    if(x < pq.top().first){
                        pq.pop();
                        pq.push({x,{arr[i],arr[j]}});
                    }
                }
                else{
                    pq.push({x,{arr[i],arr[j]}});
                }
            }
        }

        return {pq.top().second.first,pq.top().second.second};
        