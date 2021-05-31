#include <vector>
int minCostToGivenString(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
 
    if (n!=m) return -1;
    
    vector<int> a(256), b(256);
     
    for (int i=0; i<n; ++i) {
        a[str1[i]]++;
        b[str2[i]]++;
    }
    
    for (int i=0; i<256; ++i) if (a[i]!=b[i]) return -1;
    
    int i=0, j=0;
    int ans = 0;
    while (i<n) {
        while (i<n && str1[i]!=str2[j]) {
            i++;
            ans++;
        }
        if (i<n) {i++;j++;}
    }
    return ans;
}
