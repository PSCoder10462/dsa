// returns index of the element if present, else -1 (index may not be of the first occurrence everytime)

int binary_search(std::vector<int> &v, int key, int lo, int hi)
{
    if (lo > hi)
        return -1;

    int mid = (lo + hi) / 2;

    if (key == v[mid])
        return mid;

    if (key > v[mid])
        return binary_search(v, key, mid + 1, hi);
    else
        return binary_search(v, key, lo, mid - 1);
}
