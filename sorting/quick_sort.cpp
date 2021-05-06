// v is global vector to be sorted

int findPivot(int lo, int hi)
{
    // consider last element as pivot
    if (lo > hi)
        return -1;
    if (lo == hi)
        return lo;
    int pos = lo;
    for (int i = lo; i <= hi; ++i)
    {
        if (v[i] < v[hi])
        {
            std::swap(v[pos], v[i]);
            pos++;
        }
    }
    std::swap(v[pos], v[hi]);
    return pos;
}

void quickSort(int lo, int hi)
{
    if (lo >= hi)
        return;
    int pivot = findPivot(lo, hi);
    quickSort(lo, pivot - 1);
    quickSort(pivot + 1, hi);
}
