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

Node *reverseLL(Node *head) {
  if (!head or !head->next) return head;
  Node *rest = reverseLL(head->next);
  head->next->next = head;
  head->next = nullptr;
  return rest;
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

  Node *temp = nullptr;
  last = temp;
  int nodes = 0;
  for (Node *ptr = head; ptr; ptr = ptr->next) {
    nodes++;
    createNode(temp, last, ptr->data);
  }

  if (nodes <= 2) {
    printLL(head);
    return;
  }

  temp = reverseLL(temp);

  Node *a = head, *b = a->next;
  Node *c = temp, *d = c->next;

  int ctr = 0;
  while (ctr < nodes - 1) {
    ctr++;
    a->next = c;
    if (ctr == nodes - 1) {
      c->next = nullptr;
      break;
    }
    ctr++;
    c->next = b;

    if (ctr == nodes - 1) {
      b->next = nullptr;
      break;
    }

    a = b;
    c = d;
    b = b->next;
    d = d->next;
  }

  printLL(head);
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  std::cin >> T;
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
