void selectionSort(std::vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; ++i)
    {

        int min_val = v[i], pos = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (min_val > v[j])
            {
                min_val = v[j];
                pos = j;
            }
        }

        std::swap(v[i], v[pos]);
    }
}
