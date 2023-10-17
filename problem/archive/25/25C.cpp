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

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            tot += a[i][j];
        }
    }

    int k; cin >> k;
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                tot -= a[i][j];
                if (a[i][u] + a[v][j] + w < a[i][j]) {
                    a[i][j] = a[j][i] = a[i][u] + a[v][j] + w;
                }
                if (a[i][v] + a[u][j] + w < a[i][j]) {
                    a[i][j] = a[j][i] = a[i][v] + a[u][j] + w;
                }
                tot += a[i][j];
            }
        }

        cout << tot << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}