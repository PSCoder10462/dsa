/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<int, int>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Node {
public:
    char data;
    Node *left, *right;
    Node (char data) {
        this->data = data;
        left = right = nullptr;
    }
};


Node *createTree(unordered_map<char, int>m, pii iRange, string pre, 
    pii preRange) {
    // base case
    if (iRange.ss < iRange.ff or preRange.ss < preRange.ff) 
        return nullptr;

    // index of current node in inorder traversal
    int in_ind = m[pre[preRange.ff]];

    // number of elements in seft subtree
    int nel = in_ind - iRange.ff;

    Node *node = new Node(pre[preRange.ff]);
    // cout << node->data << endl;
    node->left = createTree(m, mp(iRange.ff, in_ind-1), pre, 
        mp(preRange.ff+1, preRange.ff+nel));

    node->right = createTree(m, mp(in_ind+1, iRange.ss), pre, 
        mp(preRange.ff+nel+1, preRange.ss));

    return node;
}

void postOrder(Node *root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

void solve() {
    string in, pre;
    cin >> in >> pre;

    unordered_map <char, int> m;
    loop(i, 0, (int)in.length()-1) 
        m[in[i]] = i;

    Node *root = createTree(m, mp(0, (int)pre.length()-1), pre, 
        mp(0, (int)pre.length()-1));
    
    postOrder(root);
}


int main () {
    clock_t start = clock();
    file_i_o();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
