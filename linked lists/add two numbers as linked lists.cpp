#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) ((l + h) / 2)
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define mod(a) (a % 100'000'007)
#define endl '\n'

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

class Node {
 public:
  int data;
  Node *next;
  Node(int n) {
    this->data = n;
    this->next = nullptr;
  }
};

void createNode(Node *&head, Node *&last, int n) {
  if (!head) {
    head = new Node(n);
    last = head;
  } else {
    last->next = new Node(n);
    last = last->next;
  }
}

void printLL(Node *head) {
  for (Node *ptr = head; ptr; ptr = ptr->next) cout << ptr->data << ' ';
  cout << endl;
}

Node *reverseLL(Node *head) {
  if (not head or not head->next) return head;
  Node *rest = reverseLL(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

Node *addLL(Node *F, Node *S) {
  Node *A = nullptr;
  Node *f = F, *s = S, *a = A;
  int carry = 0;
  while (f and s) {
    int sum = f->data + s->data + carry;
    carry = sum / 10;
    sum %= 10;
    createNode(A, a, sum);
    f = f->next;
    s = s->next;
  }
  while (f) {
    int sum = f->data + carry;
    carry = sum / 10;
    sum %= 10;
    createNode(A, a, sum);
    f = f->next;
  }
  while (s) {
    int sum = s->data + carry;
    carry = sum / 10;
    sum %= 10;
    createNode(A, a, sum);
    s = s->next;
  }
  if (carry) createNode(A, a, carry);
  return A;
}

void solve() {
  Node *first, *second, *last;
  first = second = last = nullptr;
  int n;
  cin >> n;
  while (n != -1) {
    createNode(first, last, n);
    cin >> n;
  }
  cin >> n;
  while (n != -1) {
    createNode(second, last, n);
    cin >> n;
  }
  first = reverseLL(first);
  second = reverseLL(second);

  Node *ans = addLL(first, second);
  printLL(reverseLL(ans));
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
