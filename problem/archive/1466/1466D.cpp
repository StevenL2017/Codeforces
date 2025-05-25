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
    multiset<int> s;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        s.insert(a[u - 1]);
        s.insert(a[v - 1]);
    }

    vector<ll> ans(n - 1);
    for (auto x: a) {
        ans[0] += x;
        s.extract(x);
    }
    for (int i = 1; i < n - 1; i++) {
        auto x = *s.rbegin();
        ans[i] = ans[i - 1] + x;
        s.extract(x);
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