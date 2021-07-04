#define vi vector<int>
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#include <math.h>

vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    // Write your code here.
    int p = pow(2, k-1);
	vi v;
    int j = 0;
  	loop(i, 0, n-1) {
        if (p&arr[i]) 
            v.push_back(arr[i]);
        else arr[j++] = arr[i];
    }
    loop(i, j, n-1)
        arr[i] = v[i-j];
 	return arr;
}
