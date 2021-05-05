std::vector <int> v;
int N, size;

void func(int n, int k) {
    // base case
    v.push_back(n);
    size++;
    if (n <= 0) {
        return ;
    }
    
    func(n-k, k);
}

void func2 (int n, int k) {
    
    v.push_back(n);
    
    if (n == N) {
        return ;
    }
    
    func2(n+k, k);
}


std::vector<int> printSeries(int n, int k)
{
    v.clear();
    size = 0;
    N = n;
	// Write your code here
    func(n, k);
    func2(v[size-1]+k, k);
	return v;
}
