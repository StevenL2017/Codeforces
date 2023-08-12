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

struct Node {
    int l, r, a, b;
};

void solve() {
    int n; cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].a >> a[i].b;
    }
    int m; cin >> m;
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(a.begin(), a.end(), [&] (Node x, Node y) { return x.l < y.l; });
    vector<Node> b(1, a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i].l <= b.back().b) {
            b.back().l = min(b.back().l, a[i].l);
            b.back().b = max(b.back().b, a[i].b);
            b.back().r = max(b.back().r, a[i].r);
        } else if (a[i].l <= b.back().r) {
            b.back().r = a[i].l - 1;
            b.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }

    sort(q.begin(), q.end());
    vi ans(m, 0);
    int j = 0, k = ssz(b);
    for (auto [x, i] : q) {
        while (j < k && b[j].r < x) {
            j++;
        }
        if (j == k || b[j].l > x) {
            ans[i] = x;
        } else {
            ans[i] = max(x, b[j].b);
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