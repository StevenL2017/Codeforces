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
    ll n;
    int m;
    cin >> n >> m;

    vi a;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }

    n = ssz(a);
    int k = 1 << n;
    vector<vector<ll>> f(k, vector<ll>(m));
    f[0][0] = 1;
    for (int mask = 0; mask < k; mask++) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                if (a[i] == 0) {
                    bool ok = false;
                    for (int c = 0; c < n; c++) {
                        if ((mask >> c & 1) && a[c]) {
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) continue;
                }
                f[mask | (1 << i)][(j * 10 + a[i]) % m] += f[mask][j];
            }
        }
    }

    ll ans = f[k - 1][0];
    map<int, int> cnt;
    for (auto x: a) {
        cnt[x]++;
    }
    for (auto [_, v]: cnt) {
        for (int x = 2; x <= v; x++) {
            ans /= x;
        }
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