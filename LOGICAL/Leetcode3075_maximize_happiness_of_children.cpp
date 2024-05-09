/* isme maine jo pichla wala hai pointer usko aur uske piche wale ko compare kiya hai 
aur jitne baar k ka value hai utni baar loop chalaya hai and each interval pe after
deducting sum i will subtract 1  from the x as well take y also in backward position 
and jitna bhi K ka value hai utna a increase hoga and fir a[x]-remaining karke dekhenge if
they are greater than 0 soo that u can add up.
 */


class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        long long sum=0;
        int remaining=0;
        sort(a.begin(),a.end());
        int n=a.size();
        int x=n-1;
        int y=n-2;
        for(int i=1;i<=k;i++){
            long actual=a[x]-remaining;
            if(actual>0){
            sum=sum+actual;
            x=n-1-i;
            y=x-1;
            remaining++;
            }else{
                break;
            }
        }
        return sum;
    }
};