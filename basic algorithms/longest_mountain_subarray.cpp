int longestMountain(int *arr, int n)
{
    int asc, desc;
    asc = desc = 0;

    int ans = 0;
    for (int i=1; i<n; ) {
        if (i<n && arr[i-1] < arr[i])
		while (i<n && arr[i-1] < arr[i]) {
            asc++; i++;
        }
        if (i<n && arr[i-1] > arr[i])
        while (i<n && arr[i-1] > arr[i]) {
            desc++; i++;
        } else ++i;
        if (asc && desc) {
            ans = std::max(ans, 1+asc+desc);
        }
        asc = desc = 0;
    }
    return ans;
}
