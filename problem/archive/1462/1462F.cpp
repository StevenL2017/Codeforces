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
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }

    sorta(a);
    vi left(n, 1), right(n, 1);
    multiset<int> s;
    rep(i, n) {
        s.insert(a[i].second);
        while (!s.empty() && *s.begin() < a[i].first) {
            s.erase(s.begin());
        }
        left[i] = ssz(s);
    }
    repd(i, n - 1, -1) {
        auto idx = upper_bound(a.begin(), a.end(), make_pair(a[i].second, INT_MAX)) - a.begin();
        right[i] = idx - i;
    }

    int ans = n - 1;
    rep(i, n) {
        ans = min(ans, n - (left[i] + right[i] - 1));
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