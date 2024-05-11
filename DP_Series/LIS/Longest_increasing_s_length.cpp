/* here we just maintain one count varibale soo and then we just keep increasing if it is equal else 
we will intialise it if it is equal if we have update the dp array then we woll initialise the count
else if dp[i]==dp[j]+1; that are equal then we will increament this count by previous index  and we just keep 
maxi for this and we will count the total ways

1)if( arr[j] < arr[i] && dp[j+1] > dp[i]), in this case we get a new LIS of greater length, 
therefore the number of LIS ending at arr[i], is the same as number of LIS ending at arr[j] 
as we simply append the element arr[j] to all those LIS. In simple terms, ct[i] = ct[j]. 
Try to dry run this example to understand: [1, 2, 3],


2)if( arr[j] < arr[i] && dp[j+1]==dp[i]) in this case we get a new LIS of same length
 at which the ct[i] is originally holding the value for. Therefore the new ct[j] value will be 
 the number of LIS that was given by its original value plus the number of LIS that ends at 
 element arr[j] at length dp[j]. In simple terms, ct[i] = ct[i] + ct[j]. Try to dry run this example to understand: [1, 5, 6, 10].
*/







int findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

    int maxi = 1; // Initialize the maximum length as 1

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i]) {
                dp[i] = dp[prev_index] + 1;
                // Inherit count
                ct[i] = ct[prev_index];
            } else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i]) {
                // Increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int numberOfLIS = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            numberOfLIS += ct[i];
        }
    }

    return numberOfLIS;
}