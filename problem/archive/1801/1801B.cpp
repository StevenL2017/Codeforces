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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    vi suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], a[i].second);
    }

    set<int> s;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int pre = -1e9;
            while (!s.empty() && *s.begin() < a[i].first) {
                pre = *s.begin();
                s.erase(s.begin());
            }
            if (!s.empty() && abs(*s.begin() - a[i].first) <= abs(pre - a[i].first)) {
                pre = *s.begin();
            }
            if (i < n - 1) {
                pre = max(pre, suf[i + 1]);
            }
            ans = min(ans, abs(pre - a[i].first));
        }
        if (i < n - 1) {
            ans = min(ans, abs(suf[i + 1] - a[i].first));
        }
        s.insert(a[i].second);
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