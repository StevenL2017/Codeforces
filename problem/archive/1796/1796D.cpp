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
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    in(a);

    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, LLONG_MIN)));
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int c = 0; c < 3; c++) {
                if (f[i][j][c] == LLONG_MIN) continue;
                for (int jj = j; jj <= min(k, j + 1); jj++) {
                    ll d = a[i] + (jj == j ? -x : x);
                    for (int cc = c; cc < 3; cc++) {
                        f[i + 1][jj][cc] = max(f[i + 1][jj][cc], f[i][j][c] + (cc == 1 ? d : 0));
                    }
                }
            }
        }
    }
    cout << max(f[n][k][1], f[n][k][2]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}