#include <algorithm>

int countOccurences(int arr[], int n, int X)
{
	//Write your code here
    int pf = std::lower_bound(arr, arr+n, X) - arr;
    if (arr[pf] != X) return 0;
    int pl = std::upper_bound(arr, arr+n, X) - arr;
    return pl-pf;
}
