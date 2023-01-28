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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, m; cin >> n >> m;
    
    vi cnt(n + 1, 0);
    repa(i, 3, n + 1) {
        int a = (i & 1) ? 1 : 0;
        int c = (i - 2 - a) / 2 + 1;
        cnt[i] = c * (a + i - 2) / 2;
    }

    if (cnt[n] < m) {
        cout << -1 << endl;
        return;
    }

    vi ans;
    int idx = lower_bound(cnt.begin(), cnt.end(), m) - cnt.begin();
    if (cnt[idx] > m) idx--;
    repa(i, 1, idx + 1) ans.push_back(i);
    m -= cnt[idx];
    if (m) {
        ans.push_back(2 * idx + 1 - 2 * m);
        idx += 2;
    }
    
    while (ssz(ans) < n) {
        ans.push_back(1e8 + 1 + 1e4 * idx);
        idx++;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}