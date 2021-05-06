void bubbleSort(std::vector<int> &v)
{
    v.insert(v.begin(), INT_MIN);
    int n = v.size();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (v[j] >= v[i + 1])
            {
                v.insert(v.begin() + j, v[i + 1]);
                v.erase(v.begin() + i + 2);
                break;
            }
        }
    }
    v.erase(v.begin());
}
