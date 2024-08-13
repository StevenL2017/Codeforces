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

    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] >> 2].push_back(i);
    }

    vi ans(n);
    for (auto [_, v]: mp) {
        int m = ssz(v);
        vi idx = v;
        sort(idx.begin(), idx.end());
        sort(v.begin(), v.end(), [&] (int i, int j) { return a[i] < a[j]; });
        for (int i = 0; i < m; i++) {
            ans[idx[i]] = a[v[i]];
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}