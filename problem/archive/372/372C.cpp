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
    int n, m, d;
    cin >> n >> m >> d;
    vi a(m), b(m), t(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }

    vector<vector<ll>> f(2, vector<ll>(n + 1, LLONG_MIN));
    for (int i = 1; i <= n; i++) {
        f[0][i] = 0;
    }

    int p = 1, pre = 1;
    for (int i = 0; i < m; i++) {
        deque<int> q;
        int range = min(1ll * n, (t[i] - pre) * 1ll * d);
        for (int j = 1; j <= range; j++) {
            while (!q.empty() && f[p ^ 1][q.back()] <= f[p ^ 1][j]) {
                q.pop_back();
            }
            q.push_back(j);
        }
        for (int j = 1; j <= n; j++) {
            int k = j + range;
            if (k <= n) {
                while (!q.empty() && f[p ^ 1][q.back()] <= f[p ^ 1][k]) {
                    q.pop_back();
                }
                q.push_back(k);
            }
            f[p][j] = f[p ^ 1][q.front()] + b[i] - abs(a[i] - j);
            while (!q.empty() && q.front() <= j - range) {
                q.pop_front();
            }
        }
        p ^= 1;
        pre = t[i];
    }

    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[p ^ 1][i]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}