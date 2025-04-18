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
    map<int, vi> cx, cy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            cx[c].push_back(i);
            cy[c].push_back(j);
        }
    }

    auto calc = [&] (map<int, vi> c) -> ll {
        ll ans = 0;
        for (auto [k, v]: c) {
            sort(begin(v), end(v));
            ll sub = 0, cnt = 0;
            for (auto x: v) {
                ans += x * cnt - sub;
                sub += x;
                cnt++;
            }
        }
        return ans;
    };
    cout << calc(cx) + calc(cy) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}