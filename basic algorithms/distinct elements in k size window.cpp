#include <unordered_map>

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
	unordered_map <int, int> mp;
    vector<int> ans;
    int dist = 0;
    for (int i=0; i<k; ++i) {
        if (!mp[arr[i]]) dist++;
        mp[arr[i]]++;
    }
    
    ans.push_back(dist);
    int j=0;
    
    for (int i=k; i<arr.size(); ++i) {
        
        mp[arr[j]]--;
        if (!mp[arr[j]]) dist--;
       	j++;
        if (!mp[arr[i]]) dist++;
        mp[arr[i]]++;
        
        ans.push_back(dist);
    }
    
    return ans;
	
}
