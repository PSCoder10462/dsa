/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<ll, ll>
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
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};


vi topView(Node *root) {
    if (!root) return vi{};
    vi left, right;
    int minLeft, maxRight;
    minLeft = maxRight = 0;
    queue<pair<Node*, int>> pri, sec;
    pri.push(mp(root, 0));
    while (!pri.empty() or !sec.empty()) {
        while (!pri.empty()) {
            auto [node, dist] = pri.front();
            pri.pop();
            if (dist < minLeft) {
                minLeft = dist;
                left.pb(node->data);
            }
            if (dist > maxRight) {
                maxRight = dist;
                right.pb(node->data);
            }
            if (node->left) 
                sec.push(mp(node->left, dist-1));
            if (node->right) 
                sec.push(mp(node->right, dist+1));
        }
        while (!sec.empty()) {
            auto [node, dist] = sec.front();
            sec.pop();
            if (dist < minLeft) {
                minLeft = dist;
                left.pb(node->data);
            }
            if (dist > maxRight) {
                maxRight = dist;
                right.pb(node->data);
            }
            if (node->left) 
                pri.push(mp(node->left, dist-1));
            if (node->right) 
                pri.push(mp(node->right, dist+1));
        }
    }
    vi ans = left;
    reverse(ans.begin(), ans.end());
    ans.pb(root->data);
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}


void solve() {

/*
        1
       / \
      2   3
     / \   \
    4   5   6
*/
    Node *root          = new Node(1);
    root->left          = new Node(2);
    root->right         = new Node(3);
    root->left->left    = new Node(4);
    root->left->right   = new Node(5);
    root->right->right  = new Node(6);
    vi ans = topView(root);
    for (auto const &i: ans) cout << i << ' ';
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
