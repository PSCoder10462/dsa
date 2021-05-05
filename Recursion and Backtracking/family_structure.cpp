// true -> male, false -> female
#include <bits/stdc++.h>

// 1 -> male, 2 -> female
std::map <pair <int, int>, int> m;
std::pair <int, int> p;

bool func(int n, long long int k) {
    // base case
    pair <int, int> gen;
    gen.first = n;
    gen.second = k;
    
    int gender = m[gen];
    if (gender == 1) return true;
    if (gender == 2) return false;
    
    bool first = k%2;
    long long int child = first ? (k+1)/2 : k/2;
    bool ans = func(n-1, child);
    if (first) {
    	m[gen] = ans ? 1 : 2;  	
    }
    else m[gen] = ans ? 2 : 1;
    return first ? ans : !ans;
}


string kthChildNthGeneration(int n, long long int k)
{
    p.first = 1;
    p.second = 1;
    m[p] = 1;
    p.first = 2;
    p.second = 1;
    m[p] = 1;
    p.first = 2;
    p.second = 2;
    m[p] = 2;
	bool male = func(n, k);
	return male ? "Male" : "Female";
}
