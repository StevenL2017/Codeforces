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
    string s;
    cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    vector<ll> row(n), col(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }

    int r = 0, c = 0;
    for (auto ch: s) {
        if (ch == 'D') {
            ll x = -row[r];
            a[r][c] = x;
            row[r] += x;
            col[c] += x;
            r++;
        } else {
            ll x = -col[c];
            a[r][c] = x;
            row[r] += x;
            col[c] += x;
            c++;
        }
    }
    a[n - 1][m - 1] = -col[m - 1];

    for (int i = 0; i < n; i++) {
        out(a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}