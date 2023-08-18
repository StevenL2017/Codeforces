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
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    auto cnt = m / k;
    if (m % k == 0 && cnt <= ak) {
        cout << 0 << endl;
        return;
    }
    m -= min(cnt, ak) * k;
    if (m <= a1) {
        cout << 0 << endl;
        return;
    }
    m -= a1;

    auto rem = m / k;
    auto ans = rem + m % k;
    if (k - m % k <= a1) {
        ans = min(ans, rem + 1);
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