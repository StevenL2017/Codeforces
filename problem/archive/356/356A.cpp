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
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    vi ans(n);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        auto it = s.lower_bound(l);
        vi tbd;
        while (it != s.end() && *it <= r) {
            if (*it != x) {
                ans[*it - 1] = x;
                tbd.push_back(*it);
            }
            it = next(it);
        }
        for (auto item: tbd) {
            s.erase(s.find(item));
        }
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