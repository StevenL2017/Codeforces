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
    int n; cin >> n;
    vi a(n); in(a);

    vector<bool> pre(n, false);
    set<int> s;
    for (int i = 0; i < n - 1; i++) {
        if (s.count(a[i])) break;
        s.insert(a[i]);
        if (*s.rbegin() == i + 1) pre[i] = true;
    }

    vector<bool> suf(n, false);
    s.clear();
    for (int i = n - 1; i > 0; i--) {
        if (s.count(a[i])) break;
        s.insert(a[i]);
        if (*s.rbegin() == n - i) suf[i] = true;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (pre[i] && suf[i + 1]) {
            ans.emplace_back(i + 1, n - 1 - i);
        }
    }

    cout << ssz(ans) << endl;
    for (auto [f, s] : ans) {
        cout << f << " " << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}