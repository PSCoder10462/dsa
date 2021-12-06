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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool checkED(string p, string c, int d, int indel, int sub) {
    int np = (int)p.length(), nc = (int)c.length();
    vvi E (np+1, vi(nc+1, -1));

    loop(i, 0, np) E[i][0] = i;
    loop(i, 0, nc) E[0][i] = i;

    loop(i, 1, np) {
        loop(j, 1, nc) {
            ll op1 = min(E[i-1][j], E[i][j-1]) + indel;
            ll op2 = E[i-1][j-1] + (p[i-1] == c[j-1] ? 0 : sub);
            E[i][j] = min(op1, op2);
        }
    }

    return E[np][nc] <= d;
}

void solve() {
    // code goes here  
    // string s= "ACGT";


    // // writing input file

    // srand((unsigned int)time(0));

    // loop(i, 1, 5) {
    //     loop(j, 1, 10) {
    //         cout << s[(int)(4.0* rand())/RAND_MAX];
    //     }
    //     cout << endl;
    // }


    // m vector
    vector<string> m(20);
    for (auto &i: m) cin >> i;

    int len = 15, d = 5, indel = 1, sub = 1;

    int min_len = max(1, len - d), max_len = min(len+d, 20);        

    // loop m vector to get parent string
    loop (mss, 0, 19) {
        // start position of parent ss from m
        loop(startp, 0, 599-len) {
            // ss starting from startp of length len
            string parent = m[mss].substr(startp, len);
            // assuming to print parent
            bool print = true;

            // loop m vector to get child ss
            loop(css, 0, 19) {
                // to avoid parent and child to be a part of same string
                if (css == mss) continue;

                // not found correct ed yet
                bool flag = false;

                // looping over child ss's length
                loop(l, min_len, max_len) {

                    // start position of child ss
                    loop(startc, 0, 599-l) {

                    // ss starting from startc of length l
                    string child = m[css].substr(startc, l);

                        // found the ss with apt ED
                        if (checkED(parent, child, d, indel, sub)) {
                            // cout << child << '\n';
                            flag = true; break;
                        }
                    }

                    // breaking child ss's length loop
                    if (flag) break;
                }

                // if we never found apt ED in the current m string
                if (!flag) {print = false; break;}
            }
            // print remains true, ie, all 19 strings had apt ED ss
            if (print) 
                cout << parent << endl; 
        }
    }
}

int main () {
    clock_t start = clock();
    file_i_o();
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}


// GAAAGGCTGTCTCAT
