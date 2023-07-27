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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    map<int, int> nxt1, pre0;
    int one = n + 1, zero = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            one = i + 1;
        }
        nxt1[i + 1] = one;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero = i + 1;
        }
        pre0[i + 1] = zero;
    }

    set<pair<int, int>> cnt;
    for (auto [l, r] : a) {
        auto left = nxt1[l], right = pre0[r];
        if (left > right) {
            left = -1;
            right = -1;
        }
        cnt.emplace(left, right);
    }

    cout << ssz(cnt) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}