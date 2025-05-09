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

const int N = 60;
const ll INF = 1e18;

vector<vector<ll>> f(N, vector<ll>(N, INF));

void calc() {
    f[0][0] = 0;
    for (int k = 0; k < N; k++) {
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (f[i][j] == INF) continue;
                if (i + k < N) f[i + k][j] = min(f[i + k][j], f[i][j] + (1ll << k));
                if (j + k < N) f[i][j + k] = min(f[i][j + k], f[i][j] + (1ll << k));
            }
        }
    }
}

void solve() {
    ll x, y;
    cin >> x >> y;

    ll ans = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((x >> i) == (y >> j)) {
                ans = min(ans, f[i][j]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}