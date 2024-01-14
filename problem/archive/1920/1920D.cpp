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
    ll f[n + 1] = {};
    vi last(n + 1), pos;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int a, x;
        cin >> a >> x;
        if (a == 1) {
            last[i] = x;
            f[i] = f[i - 1] + 1;
        } else {
            last[i] = last[i - 1];
            f[i] = ((x + 1) > 2e18 / f[i - 1]) ? (ll)2e18 : (ll)(x + 1) * f[i - 1];
            if (ok) {
                pos.emplace_back(i);
            }
        }
        if (f[i] == 2e18) {
            ok = false;
        }
    }
    
    while (m--) {
        ll k; cin >> k;
        for (int i = ssz(pos) - 1; i >= 0; i--) {
            int j = pos[i];
            if (f[j] > k && f[j - 1] < k) {
                if (k % f[j - 1] == 0) {
                    k = f[j - 1];
                    break;
                }
                k %= f[j - 1];
            }
        }
        cout << last[lower_bound(f + 1, f + n + 1, k) - f] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}