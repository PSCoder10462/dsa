#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define vi vector<int>

vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
	// Write your code here.
    vi ans(n * m);
  	k %= m;

  	if (k == 0) {
    	loop(i, 0, n - 1) loop(j, 0, m - 1) ans[i * m + j] = mat[i][j];
    	return ans;
  	}

    loop(i, 0, n-1) 
  		loop(j, m-k, m-1)
      		ans[(i*m) + (j-m+k)] = mat[i][j];
  
    loop(i, 0, n-1)    	  
  		loop(j, 0, m-k-1)
  		  	ans[(i*m) + (j+k)] = mat[i][j];
    
  	return ans;
}
