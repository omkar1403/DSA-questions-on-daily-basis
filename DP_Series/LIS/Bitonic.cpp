//first hamne increasing nikala and then reverse karke increasing nikala and unka phir point karke dono ke same index me se 1 minus kar diya


int longestBitonicSubsequence(vector<int>& arr, int n)
{
 vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]
    // Calculate the longest increasing subsequence 
    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
    }
    // Reverse the direction of nested loops to calculate the longest decreasing subsequence  
    for (int i = n - 1; i >= 0; i--) {
        for (int prev_index = n - 1; prev_index > i; prev_index--) {  
            if (arr[prev_index] < arr[i]) {
                dp2[i] = max(dp2[i], 1 + dp2[prev_index]); 
            }
        }
    }

    int maxi = -1;
	  for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
	
}
