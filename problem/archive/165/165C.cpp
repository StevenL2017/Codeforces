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
    int k; cin >> k;
    string s; cin >> s;

    int c0 = 0;
    vi zeros;
    for (auto c: s) {
        if (c == '0') {
            c0++;
        } else {
            zeros.push_back(c0); 
            c0 = 0;
        }
    }
    zeros.push_back(c0);

    ll ans = 0;
    for (int i = 0; i + k < ssz(zeros); i++) {
        ll cur = (zeros[i] + 1) * 1ll * (zeros[i + k] + 1);
        if (!k) cur = (zeros[i] + 1) * 1ll * zeros[i] / 2;
        ans += cur;
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