std::vector<int> merge(std::vector<int> v1, std::vector<int> v2)
{
    std::vector<int> ans;

    int n1 = v1.size(), n2 = v2.size();

    int i, j;
    i = j = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
            ans.push_back(v1[i++]);
        else
            ans.push_back(v2[j++]);
    }
    while (i < n1)
        ans.push_back(v1[i++]);

    while (j < n2)
        ans.push_back(v2[j++]);

    return ans;
}

std::vector<int> mergeSort(int lo, int hi)
{
    if (lo == hi)
    {
        std::vector<int> temp{v[lo]};
        return temp;
    }

    std::vector<int> v1 = mergeSort(lo, (lo + hi) / 2);
    std::vector<int> v2 = mergeSort(((lo + hi) / 2) + 1, hi);

    std::vector<int> v3 = merge(v1, v2);

    return v3;
}
