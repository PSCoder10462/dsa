void heapify(vector<int> &arr, int n, int i) {
	int lci = 2*i + 1, rci = 2*i + 2;
    int largest = i;
    if (lci < n and arr[lci] > arr[i])
        largest = lci;
    if (rci < n and arr[rci] > arr[largest])
        largest = rci;
    // base case
    if (largest == i) return;
    
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
}

vector<int> buildHeap(vector<int> arr, int n)
{	
	// Write your code here 
    for (int i=n/2-1; i>=0; --i) {
        heapify(arr, n, i);
    }
    return arr;
}
