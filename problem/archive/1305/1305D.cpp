#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

int query(int u, int v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x - 1;
}

void solve() {
    int n;
    cin >> n;
    vector<vi> e(n);
    vi deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int res = n;
    while (res > 1) {
        int u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                if (u == -1) {
                    u = i;
                } else if (v == -1) {
                    v = i;
                } else {
                    break;
                }
            }
        }
        if (u != -1 && v != -1) {
            int x = query(u, v);
            if (x == u || x == v) {
                cout << "! " << x + 1 << endl;
                cout.flush();
                return;
            } else {
                for (auto nxt: e[u]) {
                    deg[nxt]--;
                }
                for (auto nxt: e[v]) {
                    deg[nxt]--;
                }
                deg[u] = deg[v] = -1;
                res -= 2;
            }
        } else if (u != -1) {
            cout << "! " << u + 1 << endl;
            cout.flush();
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            cout << "! " << i + 1 << endl;
            cout.flush();
            return;
        }
    }
    cout << "! " << res << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}