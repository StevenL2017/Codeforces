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
    int n, h, m;
    cin >> n >> h >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    auto sub = [&] (pair<int, int> t1, pair<int, int> t2) -> pair<int, int> {
        int dt = t2.first * 60 + t2.second - (t1.first * 60 + t1.second);
        return make_pair(dt / 60, dt % 60);
    };

    auto add = [&] (pair<int, int> t1, pair<int, int> t2) -> pair<int, int> {
        int dt = t2.first * 60 + t2.second + (t1.first * 60 + t1.second);
        return make_pair(dt / 60, dt % 60);
    };

    sort(a.begin(), a.end());
    int idx = lower_bound(a.begin(), a.end(), make_pair(h, m)) - a.begin();
    pair<int, int> ans;
    if (idx < n) {
        ans = sub({h, m}, a[idx]);
    } else {
        ans = add(sub({h, m}, {24, 0}), sub({0, 0}, a[0]));
    }

    cout << ans.first << " " << ans.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}