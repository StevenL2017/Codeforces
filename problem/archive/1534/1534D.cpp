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

vi query(int x, int n) {
    cout << "? " << x << endl;
    cout.flush();
    vi a(n);
    in(a);
    return a;
}

void solve() {
    int n;
    cin >> n;

    auto e = query(1, n);
    vector<vi> s(2);
    set<pair<int, int>> ans;
    for (int i = 2; i <= n; i++) {
        s[e[i - 1] & 1].push_back(i);
        if (e[i - 1] == 1) {
            ans.emplace(1, i);
        }
    }

    if (ssz(s[0]) > ssz(s[1])) {
        swap(s[0], s[1]);
    }

    for (auto u: s[0]) {
        e = query(u, n);
        for (int i = 1; i <= n; i++) {
            if (e[i - 1] == 1) {
                ans.emplace(min(u, i), max(u, i));
            }
        }
    }

    cout << "!" << endl;
    for (auto [a, b]: ans) {
        cout << a << " " << b << endl;
    }
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}