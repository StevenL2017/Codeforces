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
    ll n, k;
    cin >> n >> k;

    vector<ll> pre, suf;
    for (int i = 1; i * 1ll * i <= n; i++) {
        if (n % i == 0) {
            pre.emplace_back(i);
            if (i * 1ll * i < n) {
                suf.emplace_back(n / i);
            }
        }
    }

    if (k > ssz(pre) + ssz(suf)) {
        cout << -1 << endl;
        return;
    }

    if (k <= ssz(pre)) {
        cout << pre[k - 1] << endl;
    } else {
        cout << suf[ssz(pre) + ssz(suf) - k] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}