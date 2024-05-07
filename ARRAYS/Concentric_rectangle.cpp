/*4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
*/


vector<vector<int> > Solution::prettyPrint(int a) {
     int n = 2 * a - 1; // size of the pattern
    vector<vector<int>> mat(n, vector<int>(n, 0));

    // Filling the matrix with the pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = a - min(min(i, j), min(n - 1 - i, n - 1 - j));
        }
    }

    return mat;
}
