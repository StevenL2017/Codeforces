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
    vi a(n); in(a);

    vector<ll> suf(n + 1);
    for (int i = n - 2; i > 0; i -= 2) {
        suf[i] = suf[i + 1] + max({0, a[i - 1] + 1 - a[i], a[i + 1] + 1 - a[i]});
        suf[i - 1] = suf[i];
    }
    
    ll ans = LLONG_MAX, pre = 0;
    for (int i = 1; i < n - 1; i += 2) {
        ans = min(ans, pre + suf[i]);
        pre += max({0, a[i - 1] + 1 - a[i], a[i + 1] + 1 - a[i]});
    }
    ans = min(ans, pre);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}