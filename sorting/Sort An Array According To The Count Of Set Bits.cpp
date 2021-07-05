// using multimap

#include <map>
#include <iterator>

int cntbit(int n) {
    int cnt = 0;
    while (n) {
        if (1 & n) cnt++;
        n = n >> 1;
    }
    return cnt;
}

void sortSetBitsCount(vector<int>& arr, int size)
{
	// Write your code here
    multimap <int, int> m;
    
    for (int i: arr) 
        m.insert(std::make_pair(-1*cntbit(i), i));
    
    multimap <int, int> :: iterator itr;
    
    int i = 0;
    for (itr=m.begin(); itr != m.end(); itr++)
        arr[i++] = itr->second;
    
}
