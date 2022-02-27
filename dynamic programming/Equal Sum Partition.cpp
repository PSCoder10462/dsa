// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        // code here
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += a[i];
        if (sum & 1) return false;
        int reqd = (sum >> 1);
        vector<bool> v(reqd+1, false);
        v[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = reqd; j - a[i] >= 0; --j) {
                int val = j - a[i];
                if (!v[j]) {
                    v[j] = v[val];
                }
            }    
        }
        return v[reqd];
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends
