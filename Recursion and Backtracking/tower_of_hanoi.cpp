std::vector <vector <int>> ans;

// from, aux, target
void toh(int n, int f, int a, int t) {
    // base case
    if (n==1) {
        // move the disc f to t
        vector <int> temp {f, t};
        ans.push_back(temp);
        return;
    }
    
    toh(n-1, f, t, a);
    
    // move the last disc
    vector <int> temp {f, t};
    ans.push_back(temp);
    
    toh(n-1, a, f, t);
}


vector<vector<int>> towerOfHanoi(int n)
{
    
    ans.clear();
    toh(n, 1, 2, 3);   
    return ans;
}
