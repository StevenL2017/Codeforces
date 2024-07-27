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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    ll ans = 0;
    map<tuple<int, int, int>, int> cnt;
    for (int i = 0; i < n - 2; i++) {
        ans += cnt[{a[i], a[i + 1], 0}] + cnt[{a[i], 0, a[i + 2]}] + cnt[{0, a[i + 1], a[i + 2]}];
        ans -= 3ll * cnt[{a[i], a[i + 1], a[i + 2]}];
        cnt[{a[i], a[i + 1], 0}]++;
        cnt[{a[i], 0, a[i + 2]}]++;
        cnt[{0, a[i + 1], a[i + 2]}]++;
        cnt[{a[i], a[i + 1], a[i + 2]}]++;
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