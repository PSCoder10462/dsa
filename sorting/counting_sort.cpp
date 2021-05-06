// v is a global vector to be sorted

std::vector<int> countingSort()
{
    std::vector<int> aux;
    for (auto x : v)
    {
        if (x > aux.size())
            aux.resize(x + 1, 0);
        aux[x]++;
    }

    std::vector<int> output;

    for (int i = 0; i < aux.size(); i++)
    {
        for (int j = 0; j < aux[i]; j++)
            output.push_back(i);
    }

    return output;
}
