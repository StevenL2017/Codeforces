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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m)), b(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }
    for (int i = 0; i < n; i++) {
        in(b[i]);
    }

    vector<pair<int, int>> pa(n * m), pb(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pa[a[i][j] - 1] = {i, j};
            pb[b[i][j] - 1] = {i, j};
        }
    }

    vector<set<int>> row(n), col(m);
    for (int i = 0; i < n * m; i++) {
        row[pa[i].first].insert(pb[i].first);
        col[pa[i].second].insert(pb[i].second);
    }

    for (int i = 0; i < n; i++) {
        if (ssz(row[i]) > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int j = 0; j < m; j++) {
        if (ssz(col[j]) > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}