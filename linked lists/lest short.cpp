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
  if (not head) {
    head = new Node(n);
    last = head;
  } else {
    last->next = new Node(n);
    last = last->next;
  }
}

void printLL(Node *head) {
  for (Node *ptr = head; ptr; ptr = ptr->next) cout << ptr->data << " ";
  cout << endl;
}

Node *del(Node *head) {
  if (not head or not head->next) return head;
  for (Node *ptr = head; ptr and ptr->next; ptr = ptr->next) {
    Node *temp = ptr;
    while (temp and temp->next and temp->data > temp->next->data) {
      temp = temp->next;
    }
    ptr->next = temp->next;
  }
  return head;
}

void solve() {
  Node *head, *last;
  head = last = nullptr;
  int n;
  cin >> n;
  while (n != -1) {
    createNode(head, last, n);
    cin >> n;
  }
  printLL(head);
  head = del(head);
  printLL(head);
}

int32_t main() {
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
