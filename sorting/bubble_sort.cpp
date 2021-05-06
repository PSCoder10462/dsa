void bubbleSort(std::vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
        }
    }
}
