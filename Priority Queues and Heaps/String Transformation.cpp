#include <queue>

string getTransformedString(string str, int k)
{
    //Write your code here
	int n = str.length();
    priority_queue<char, vector<char>, greater<char>> Q;
  	string output;
    for (int i=0; i<min(k, n); ++i) Q.push(str[i]);
    for (int i=k; i<n; ++i) {
        output.push_back(Q.top()); Q.pop();
        Q.push(str[i]);
    }
    while (!Q.empty()) {
        output.push_back(Q.top()); Q.pop();
    }
    return output;
}
