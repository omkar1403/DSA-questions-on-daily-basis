/*In this we have maintain the hash table to print the array soo that we can print the elements and we took 
last index soo that from last index we can print the array agar samjh hash ka jo index hai vo index ke equal nahi
hoga khud ke tab tak ham loop chalyenge and this is the way to print the  characters*/


vector<int> divisibleSet(vector<int>& arr) {
    int n = arr.size();

    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);   // dp[i] stores the length of the divisible subset ending at arr[i]
    vector<int> hash(n, i); // hash[i] stores the previous index in the divisible subset ending at arr[i]

    for (int i = 0; i < n; i++) {
        hash[i] = i; // Initialize with the current index
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    //soo in this way we can store the last index
    temp.push_back(arr[lastIndex]);

    // Reconstruct the divisible subset using the hash table
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];   //here we keep the track of the last index and assign it to the next index
        temp.push_back(arr[lastIndex]);
    }

    // Reverse the array to get the correct order
    reverse(temp.begin(), temp.end());

    return temp;
}