void heapify(long *arr, int n, int i) {
    int lci = 2*i + 1, rci = 2*i + 2;
    int largest = i;
    if (lci < n and arr[i] < arr[lci])
        largest = lci;
    if (rci < n and arr[largest] < arr[rci])
        largest = rci;
    if (largest == i) return;
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
}

void minHeapToMaxHeap(long *arr, int n)
{
    //Write your code here
    for (int i=n/2-1; i>=0; --i) {
        heapify(arr, n, i);
    }
}
