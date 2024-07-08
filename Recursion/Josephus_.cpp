//approach 1
class Solution {
public:
 int solve(int n,int k)
    {
        if(n==1) return 0;
        int x=solve(n-1,k);
        int y=(x+k)%n; // YOU HAVE TO RETURN EVERY ELEMENT WITHIN RANGE
        return y;
    }
    int findTheWinner(int n, int k) {
     if(k>n) k=k%n;  //IF THAT IS THE CASE THEN K=K%N
        return solve(n,k)+1;  //ADD 1 HERE TO CONVERT IT INTO 1 BASES INDEXING
    }
};


//APPROACH 2

 int findTheWinner(int n, int k) {
        queue<int>q;  //HERE WE JUST TAKE QUEUE
        int i=1;
        while(i<=n){
            q.push(i); 
            i++;
        }
        while(q.size()!=1){
            int j=1; //INITIALIZE EVERYTIME FROM THIS POINT
            while(j<k){
                q.push(q.front()); //HERE MOVE THE POINTS TO THE NEXT FRONT
                q.pop();
                j++;
            }
            q.pop();  //POP FROM THE QUEUE
        }
       return q.front(); //RETURN THE FRONT ELEMENT
    }