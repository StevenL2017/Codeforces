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
    vi a(n);
    in(a);

    ll ans = 0, tot = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        ans = max(ans, tot + a[i] - (i + 1) * 1ll * d);
        if (a[i] >= 0) {
            s.insert(a[i]);
            tot += a[i];
        }
        if (ssz(s) >= m) {
            tot -= *s.begin();
            s.erase(s.begin());
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}