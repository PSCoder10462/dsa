bool canBuy(int n, int r, int k, int c, int m) {
    return m <= n and ((n-m)*(long long)k)+r >= (long long)m*c;
}

int recyclePens(int n, int r, int k, int c ){

	// Write your code here.m
    int l = 0, h = n;
    while (l <= h) {
        int m = ((long long)l+h)/2;
            bool check = canBuy(n, r, k, c, m);

        if (check and (not canBuy(n, r, k, c, m+1)))
            return m;
       	
        if (check) l = m+1;
       
        else h = m-1;
    }
    return 0; 
}
