void inplaceRotate(vector<vector<int>> &inputArray)
{
    // Write your code here.
    int n = inputArray.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = inputArray[i][j];
            inputArray[i][j] = inputArray[j][n - 1 - i]; 
            inputArray[j][n - 1 - i]
                = inputArray[n - 1 - i][n - 1 - j];
            inputArray[n - 1 - i][n - 1 - j]
                = inputArray[n - 1 - j][i];
            inputArray[n - 1 - j][i] = temp;
        }
    }
}
