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

    multiset<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (a[i]) s.emplace(a[i], i + 1);
    }

    vector<pair<int, int>> ans;
    while (ssz(s) > 1) {
        auto mn = *s.begin(), mx = *s.rbegin();
        ans.emplace_back(mn.second, mx.second);
        s.erase(s.find(mn));
        s.erase(s.find(mx));
        mn.first--;
        mx.first--;
        if (mn.first) s.emplace(mn);
        if (mx.first) s.emplace(mx);
    }

    cout << ssz(ans) << endl;
    for (auto v : ans) {
        cout << v.first << " " << v.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}